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
			SensorInformation.Name = "GearVR";
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
				isConnected = false;
				Sensor::SetStatus(Sensors::Status::Faulted);
			}
			else
			{
				result = ovr_Create(&session, &luid);
				if (OVR_FAILURE(result))
				{
					ovr_Shutdown();
					isConnected = true;
					Sensor::SetStatus(Sensors::Status::Faulted);
				}
				else if (OVR_SUCCESS(result))
				{
					isConnected = true;
					Sensor::SetStatus(Sensors::Status::Connected);
					ovrHmdDesc hmdDescription = ovr_GetHmdDesc(session);
					hmdProductName = hmdDescription.ProductName;
				}
				else
				{
					isConnected = false;
					Sensor::SetStatus(Sensors::Status::Unknown);
				}
			}


			return frame;
		}

		Frame GearVR::Disconnect()
		{
			ovr_Destroy(session);
			ovr_Shutdown();
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

			/*
			// returns true after a Gear VR touchpad tap
			OVRInput.GetDown(OVRInput.Button.One);
   
			// returns true on the frame when a user’s finger pulled off Gear VR touchpad controller on a swipe down
			OVRInput.GetDown(OVRInput.Button.DpadDown);
   
			// returns true the frame AFTER user’s finger pulled off Gear VR touchpad controller on a swipe right
			OVRInput.GetUp(OVRInput.RawButton.DpadRight);
   
			// returns true if the Gear VR back button is pressed
			OVRInput.Get(OVRInput.Button.Two);    
			*/
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
			return isConnected;
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