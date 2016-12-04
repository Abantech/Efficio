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
				virtual Sensors::TrackingType TrackingTypes() override;
				virtual Frame Connect() override;
				virtual Frame Disconnect() override;
				virtual bool HasFrame() override;
				virtual Frame GetFrame() override;

			private:
				Leap::Controller controller;
				Leap::Frame lastLeapFrame;
				bool connectionStateChanged;
				bool hasConnected;

				/// <summary>
				/// Converts Leap Motion hand to Efficio hand
				/// </summary>
				/// <param name="hand">The hand to convert</param>
				/// <returns>The converted hand</returns>
				Models::Body::Hand convertToEfficioHand(Leap::Hand hand);

				/// <summary>
				/// Converts Leap Motion finger to Efficio hand
				/// </summary>
				/// <param name="finger">The finger to convert</param>
				/// <returns>The converted finger</returns>
				Models::Body::Finger convertToEfficioFinger(Leap::Finger finger);
			};
		}
	}
}