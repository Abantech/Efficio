#pragma once

#include "Sensor.h"
#include "Hand.h"
#include "Finger.h"
#include "pxcsensemanager.h"
#include "pxchanddata.h"
#include "pxchandconfiguration.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		/// <summary>
		/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
		/// </summary>
		/// <seealso cref="Sensor" />
		extern class DLLEXPORT RealSense : public Sensor
		{
		public:
			RealSense();
			RealSense(TrackingType trackingType);
			~RealSense();
			// Inherited via Sensor
			virtual Sensors::TrackingType TrackingTypes() override;

			virtual Frame Connect() override;

			virtual Frame Disconnect() override;

			virtual Efficio::Frame GetFrame() override;
		private:
			PXCSession* session;
			PXCSenseManager* senseManager;
			PXCHandModule* handModule;
			PXCHandData* handDataOutput;
			PXCHandConfiguration* handConfiguration;
			PXCFaceModule* faceModule;
			PXCFaceData* faceDataOutput;
			PXCFaceConfiguration* faceConfiguration;
			void ReleaseAll();
			TrackingType trackingType;
			void EnableModule();

			virtual bool HasFrame() override;

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
	}
}