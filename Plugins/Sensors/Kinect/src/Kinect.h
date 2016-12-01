#pragma once

#include "Sensor.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors 
	{
		namespace Body
		{
			/// <summary>
			/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
			/// </summary>
			/// <seealso cref="Sensor" />
			extern class DLLEXPORT Kinect : public Sensor
			{
			public:
				Kinect();
				~Kinect();

				// Inherited via Sensor
				virtual Sensors::Status Status() override;
				virtual Sensors::TrackingType TrackingTypes() override;
				virtual void Connect() override;
				virtual void Disconnect() override;
				virtual bool HasFrame() override;
				virtual Frame GetFrame() override;
				virtual std::string GetSource() override;
			};
		}
	}
}