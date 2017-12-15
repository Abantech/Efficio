#pragma once

#include "IHandSensor.h"
#include "IImageSensor.h"
#include "Sensor.h"
#include "Leap.h"

namespace Efficio
{
	namespace Assets
	{
		/// <summary>
		/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
		/// </summary>
		/// <seealso cref="Sensor" />
		class LeapMotionSensor : public Models::Body::IHandSensor, public Models::AudioVisual::IImageSensor, public Sensor
		{
			friend class LeapMotion;
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

			// Inherited via IHandSensor
			virtual void EnableHandTracking(bool enable) override;

			// Inherited via IImageSensor
			virtual void EnableImageTracking(bool enable) override;

		private:
			virtual Models::Body::HandData GetHandData() override;
			virtual Models::AudioVisual::ImageData GetImageData() override;

			// Leap Motion Specific
			Leap::Controller controller;
			Leap::Frame latestLeapFrame;
			long long lastLeapFrameID;
			bool trackingHands;
			bool trackingImages;

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