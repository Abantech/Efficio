#include "GearVR.h"
#include "Event.h"
#include "EventType.h"
#include "GearVRAction.h"

namespace Efficio
{
	namespace Sensors
	{
		GearVR::GearVR()
		{
			SensorInformation.Name = "Gear VR";
		}
		GearVR::~GearVR()
		{
		}

		Frame GearVR::Connect()
		{
			auto frame = Sensor::Connect();
			ovrResult result = ovr_Initialize(nullptr);
			if (OVR_FAILURE(result))
			{
				Sensor::SetStatus(Sensors::Status::Faulted);
			}
			else
			{
				result = ovr_Create(&session, &luid);
				if (OVR_FAILURE(result))
				{
					ovr_Shutdown();
					Sensor::SetStatus(Sensors::Status::Faulted);
				}
			}

			return frame;
		}

		Frame GearVR::Disconnect()
		{
			return Sensor::Disconnect();
		}

		TrackingType GearVR::TrackingTypes()
		{
			return TrackingType::Unknown;
		}

		std::vector<std::shared_ptr<Data::Data>> GearVR::GetData()
		{
			return std::vector<std::shared_ptr<Data::Data>>();
		}

		std::vector<std::shared_ptr<Events::Event>> GearVR::GetEvents()
		{
			std::vector<std::shared_ptr<Events::Event>> events;

			ovrInputState state;
			ovr_GetInputState(session, ovrControllerType_::ovrControllerType_Active, &state);

			if (state.Buttons & ovrButton_Back)
			{
				Efficio::Sensors::GearVRAction action(Efficio::Sensors::ButtonType::Back);
				std::shared_ptr<Events::Event> eventSharedPtr(&action);
				events.push_back(eventSharedPtr);
			}

			if (state.Buttons & ovrButton_Left)
			{
				Efficio::Sensors::GearVRAction action(Efficio::Sensors::ButtonType::Left);
				std::shared_ptr<Events::Event> eventSharedPtr(&action);
				events.push_back(eventSharedPtr);
			}

			if (state.Buttons & ovrButton_Right)
			{
				Efficio::Sensors::GearVRAction action(Efficio::Sensors::ButtonType::Right);
				std::shared_ptr<Events::Event> eventSharedPtr(&action);
				events.push_back(eventSharedPtr);
			}
			{
				Efficio::Sensors::GearVRAction action(Efficio::Sensors::ButtonType::Left);
				std::shared_ptr<Events::Event> eventSharedPtr(&action);
				events.push_back(eventSharedPtr);
			}

			return events;
		}

		bool GearVR::IsConnected()
		{
			return false;
		}

		bool GearVR::HasFrame()
		{
			return false;
		}

		void GearVR::PreGetFrame()
		{
		}

		void GearVR::PostGetFrame()
		{
		}
	}
}