#pragma once

#include "Sensor.h"
#include "Leap.h"
#include "Hand.h"
#include "IHandSensor.h"

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
		namespace Body
		{
			/// <summary>
			/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
			/// </summary>
			/// <seealso cref="Sensor" />
			class DLLEXPORT LeapMotion : public Sensor, public IHandSensor
			{
			public:
				LeapMotion();
				~LeapMotion();

				// Inherited via Sensor
				virtual Sensors::TrackingType TrackingTypes() override;

			protected:
				// Inherited via Sensor
				virtual std::vector<std::shared_ptr<Data::Data>> GetData() override;
				virtual std::vector<std::shared_ptr<Events::Event>> GetEvents() override;
				virtual Frame Connect() override;
				virtual Frame Disconnect() override;
				virtual bool HasFrame() override;
				virtual void PreGetFrame() override;
				virtual void PostGetFrame() override;
				virtual bool IsConnected() override;

			private:
				// Inherited via IHandSensor
				virtual void EnableHandTracking(bool enable) override;
				virtual Data::Body::HandData GetHandData() override;
				
				// Leap Motion Specific
				Leap::Controller controller;
				Leap::Frame latestLeapFrame;
				long long lastLeapFrameID;

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