#pragma once

#include "IHandSensor.h"
#include "IImageSensor.h"
#include "Sensor.h"
#include "Hand.h"
#include "Finger.h"
#include "HandData.h"
#include "pxcsensemanager.h"
#include "pxchanddata.h"
#include "pxchandmodule.h"
#include "pxchandconfiguration.h"
#include "SampleReader.h"

namespace Efficio
{
	namespace Assets
	{
		/// <summary>
		/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
		/// </summary>
		/// <seealso cref="Sensor" />
		class RealSenseSensor : public Models::Body::IHandSensor, public Models::AudioVisual::IImageSensor, public Sensor
		{
			friend class RealSense;
		public:
			RealSenseSensor();
			~RealSenseSensor();

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
			bool trackingHands;
			bool trackingImages;
			bool trackingFaces;

			PXCSession* session;
			PXCSenseManager* senseManager;

			// Hand parts
			PXCHandModule* handModule;
			PXCHandData* handDataOutput;
			PXCHandConfiguration* handConfiguration;

			// Face parts
/*			PXCFaceModule* faceModule;
			PXCFaceData* faceDataOutput;
			FaceConfiguration* faceConfiguration*/;

			// Image Part
			Intel::RealSense::SampleReader* sampleReader;

			void ReleaseAll();
			void EnableModule();

			/// <summary>
			/// Converts RealSense hand to Efficio hand
			/// </summary>
			/// <param name="hand">The hand to convert</param>
			/// <returns>The converted hand</returns>
			Models::Body::Hand convertToEfficioHand(PXCHandData::IHand* hand);

			/// <summary>
			/// Converts RealSense finger to Efficio hand
			/// </summary>
			/// <param name="finger">The finger to convert</param>
			/// <returns>The converted finger</returns>
			Models::Body::Finger convertToEfficioFinger(Models::Body::BodySide side, Models::Body::FingerType fingerType, PXCHandData::FingerData finger, PXCHandData::JointData tip, PXCHandData::JointData dip, PXCHandData::JointData pip, PXCHandData::JointData mcp);

		};

	};
}