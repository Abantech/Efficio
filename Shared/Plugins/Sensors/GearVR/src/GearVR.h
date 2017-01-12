#pragma once

#include "Sensor.h"
//#include <OVR_CAPI.h>

#if WINDOWS
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace Sensors
	{
		class DLLEXPORT GearVR : public Sensor
		{
		public:
			GearVR();
			~GearVR();

		protected:
			// Inherited via Sensor
			virtual Frame Connect() override;
			virtual Frame Disconnect() override;
			virtual TrackingType TrackingTypes() override;
			virtual std::vector<std::shared_ptr<Data::Data>> GetData() override;
			virtual std::vector<std::shared_ptr<Events::Event>> GetEvents() override;
			virtual bool IsConnected() override;
			virtual bool HasFrame() override;
			virtual void PreGetFrame() override;
			virtual void PostGetFrame() override;

		private:
			//ovrSession session;
			//ovrGraphicsLuid luid;
			bool isConnected;
			std::string hmdProductName;
		};
	}
}