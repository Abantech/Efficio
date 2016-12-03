#pragma once

#include "SensorStatus.h"
#include "SensorDetails.h"
#include "TrackingType.h"
#include "Vector3.h"
#include "Frame.h"
#include <string>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors 
	{
		/// Any sensor which can feed data into Efficio
		extern class DLLEXPORT Sensor
		{
		public:
			Sensor() {};
			~Sensor() {};

			/// The unique ID of the device
			std::string ID;

			/// A Boolean indicating whether or not the device is enabled
			bool Enabled;

			/// A Boolean indicating whether or not the device is connected and ready to feed data into Efficio
			bool Connected();

			/// The status of the device
			virtual Status GetStatus();

			/// The type of data the device is able to track
			virtual TrackingType TrackingTypes() = 0;

			/// Connects the device
			virtual void Connect() = 0;

			/// Disconnects the device
			virtual void Disconnect() = 0;

			/// A Boolean indicating whether or not the device has a new frame for Efficio
			virtual bool HasFrame() = 0;

			/// Gets the current frame from the device
			virtual Efficio::Frame GetFrame() = 0;

			virtual std::string GetSource();

			virtual SensorInformation GetSensorInformation();

		protected:
			Efficio::Frame LastEfficioFrame;
			SensorInformation SensorInformation;
			Sensors::Status Status;
		};
	}
}