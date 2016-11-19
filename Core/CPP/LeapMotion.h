#pragma once

#include "Sensor.h"
#include "Leap.h"
#include "Hand.h"

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
			extern class DLLEXPORT LeapMotion : public Sensor
			{
			public:
				LeapMotion();
				~LeapMotion();

				// Inherited via Sensor
				virtual Efficio::DeviceStatus Status() override;
				virtual Efficio::TrackingType TrackingTypes() override;
				virtual void Connect() override;
				virtual void Disconnect() override;
				virtual bool HasFrame() override;
				virtual Efficio::Frame GetFrame() override;

			private:
				Leap::Controller controller;
				Leap::Frame lastLeapFrame;
				Efficio::Frame lastEfficioFrame;

				/// <summary>
				/// Converts Leap Motion hand to Efficio hand
				/// </summary>
				/// <param name="hand">The hand to convert</param>
				/// <returns>The converted hand</returns>
				Efficio::Models::Body::Hand convertToEfficioHand(Leap::Hand hand);

				/// <summary>
				/// Converts Leap Motion finger to Efficio hand
				/// </summary>
				/// <param name="finger">The finger to convert</param>
				/// <returns>The converted finger</returns>
				Efficio::Models::Body::Finger convertToEfficioFinger(Leap::Finger finger);
			};
		}
	}
}