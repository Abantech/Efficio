#include "Kinect.h"

namespace Efficio
{
	namespace Sensors
	{
		namespace Body
		{
			Kinect::Kinect()
			{
				SensorInformation.Name = "Microsoft Kinect";
			}

			Kinect::~Kinect()
			{
			}

			Sensors::TrackingType Kinect::TrackingTypes()
			{
				return Sensors::TrackingType::Unknown;
			}

			void Kinect::Connect()
			{
			}

			void Kinect::Disconnect()
			{
			}

			bool Kinect::HasFrame()
			{
				return false;
			}

			/// <summary>
			/// Gets the frame.
			/// </summary>
			/// <returns></returns>
			Frame Kinect::GetFrame()
			{
				Frame efficioFrame;

				// Get Kinect Frame

				// For each body					
					// Build Efficio Body

					// For each joint
						//Convert joint to Efficio Joint
						// Populate

				// Add Body to SkeletonData

				// Add data to EfficioFrame

				return efficioFrame;
			}
		}
	}
}