#include "Engine.h"
#include "EfficioStarted.h"
#include "LeapMotion.h"

namespace Efficio {
	Engine::Engine() : started(false), frameID(1), MessageBus(MessageBus::Current())
	{
			//assets.push_back(new Sensors::RealSense(Efficio::Sensors::TrackingType::Hand));
			assets.push_back(new Assets::LeapMotion());
			//assets.push_back(new Sensors::Body::Kinect());
			//assets.push_back(new Sensors::GearVR());
	}

	Engine::~Engine()
	{
	}

	Frame Engine::Start()
	{
		std::shared_ptr<Frame> startFrame(new Frame(NULL, frameID++));

		startFrame->AddEvent(std::shared_ptr<Event>(new EfficioStarted()));

		// TODO execute OnStart actions

		// Connect to all sensors
		for (size_t i = 0; i < assets.size(); i++)
		{
			auto sensors = assets[i]->GetSensors();
			for (size_t j = 0; j < sensors.size(); j++)
			{
				startFrame->AddFrame(sensors[j]->Connect());
			}
		}

		historicalFrames.AddFrame(startFrame);

		return *startFrame;
	}

	std::shared_ptr<Frame> Engine::GetFrame()
	{
		// Clean out leftover messages
		MessageBus->ClearMessages();

		std::shared_ptr<Frame> frame(new Frame(GetFrame(1), frameID++));
		deltaTimeSum += frame->DeltaTime;

		// TODO execute BeforeDeviceQuery actions

		// Query sensors for frames
		for (size_t i = 0; i < assets.size(); i++)
		{
			auto sensors = assets[i]->GetSensors();

			for (size_t j = 0; j < sensors.size(); j++)
			{
				frame->AddFrame(sensors[j]->GetFrame());
			}
		}


		// TODO execute AfterDeviceQuery actions

		// TODO execute BeforeFrameProcess actions

		auto detectedEvents = ire.ProcessFrame(frame);
		frame->AddEvents(detectedEvents);

		// TODO execute AfterFrameProcess actions

		// Save frame
		if (historicalFrames.historicalFrames.at(59) != NULL)
		{
			deltaTimeSum -= GetFrame(60)->DeltaTime;
		}
		historicalFrames.AddFrame(frame);

		auto events = frame->GetEvents();
		for (size_t i = 0; i < events.size(); i++)
		{
			auto ev = events[i];
			MessageBus->SendMessage(Efficio::Message(ev->GetEventType(), ev));
		}

		MessageBus->Notify();

		return frame;
	}


	std::shared_ptr<Efficio::Frame> Engine::GetFrame(int count)
	{
		auto tempFrame = historicalFrames.GetFrame(count);

		if (tempFrame)
		{
			return historicalFrames.GetFrame(count);
		}

		return NULL;
	}

	void Engine::ReleaseFrame()
	{
		MessageBus->Notify();
	}

	float Engine::GetFrameRate()
	{
		return  60 / (deltaTimeSum / 1000);
	}

}