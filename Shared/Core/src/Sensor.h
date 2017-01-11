#pragma once

#include "SensorStatus.h"
#include "SensorInformation.h"
#include "TrackingType.h"
#include "Vector3.h"
#include "Frame.h"
#include <string>

#if _WINDLL
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
		/// Any sensor which can feed data into Efficio
		class DLLEXPORT Sensor
		{
		public:
			Sensor();
			~Sensor() {};

			/// The type of data the device is able to track
			virtual TrackingType TrackingTypes() = 0;

			// Virtual Methods
			/// Connects the device
			virtual Frame Connect();

			/// Disconnects the device
			virtual Frame Disconnect();

			/// The unique ID of the device
			std::string ID;

			/// A Boolean indicating whether or not the device is enabled
			bool Enabled;

			/// The status of the device
			Status GetStatus();

			/// Gets the current frame from the device
			Efficio::Frame GetFrame();

			virtual std::string GetSource();

			virtual SensorInformation GetSensorInformation();

		protected:
			Efficio::Frame LastEfficioFrame;
			SensorInformation SensorInformation;
			void SetStatus(Sensors::Status status);

			virtual std::vector<std::shared_ptr<Data::Data>> GetData() = 0;
			virtual std::vector<std::shared_ptr<Events::Event>> GetEvents() = 0;			
			/// A Boolean indicating whether or not the device is connected and ready to feed data into Efficio
			virtual bool IsConnected() = 0;
			/// A Boolean indicating whether or not the device has a new frame for Efficio
			virtual bool HasFrame() = 0;
			virtual void PreGetFrame() = 0;
			virtual void PostGetFrame() = 0;


		private:
			Sensors::Status status;
			bool connectionStatusChanged;
		};
	}
}