#pragma once

#include "IHandSensor.h"
#include "Leap.h"

namespace Efficio
{
	namespace Assets
	{
		/// <summary>
		/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
		/// </summary>
		/// <seealso cref="Asset" />
		class LeapMotionSensor : public Efficio::Models::Body::IHandSensor
		{
		public:
			LeapMotionSensor();
			~LeapMotionSensor();

			// Inherited via Sensor
			virtual std::string TrackingType() override;

		protected:
			// Inherited via Sensor
			virtual std::vector<std::shared_ptr<Data>> GetData() override;
			virtual std::vector<std::shared_ptr<Event>> GetEvents() override;
			virtual Frame Connect() override;
			virtual Frame Disconnect() override;
			virtual bool HasFrame() override;
			virtual void PreGetFrame() override;
			virtual void PostGetFrame() override;
			virtual bool IsConnected() override;

		private:
			// Inherited via IHandSensor
			virtual void EnableHandTracking(bool enable) override;
			virtual Efficio::Models::Body::HandData GetHandData() override;

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

	};
}