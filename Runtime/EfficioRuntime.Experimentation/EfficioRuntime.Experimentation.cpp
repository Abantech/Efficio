// EfficioRuntime.Experimentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "FaceData.h"

int main()
{
	auto engine = new Efficio::Engine();
	auto f = engine->Start();

	while (true)
	{
		auto frame = engine->GetFrame();
		auto events = frame->GetEvents();
		auto data = frame->GetData();

		for (size_t i = 0; i < data.size(); i++)
		{
			if (data[i]->GetDataType() == Efficio::Data::DataType::Face)
			{
				auto face = dynamic_cast<Efficio::Data::Body::Face::FaceData*>(data[i].get());

				for (size_t j = 0; j < face->Expressions.size(); j++)
				{
					auto exp = face->Expressions.at(Efficio::Data::Body::Face::Expressions::OpenMouth);
					if (exp > 50)
					{
						cout << "Open mouth intensity: " << exp << "\n";
					}

				}
			}
		}

		for (size_t i = 0; i < events.size(); i++)
		{
			auto ev = events.at(i);
			std::string evName;

			switch (ev->GetEventType())
			{
			case Efficio::Events::EventType::SensorConnected:
			{
				evName = "Sensor Connected";
				break;
			}
			case Efficio::Events::EventType::SensorDisconnected:
			{
				evName = "Sensor Disconnected";
				break;
			}
			case Efficio::Events::EventType::Pinch:
			{
				evName = "Pinch";
				break;
			}
			default:
				break;
			}

			cout << ev->ID << ": " << evName << " : " << +engine->GetFrameRate() << "\n";
		}
	}
}

