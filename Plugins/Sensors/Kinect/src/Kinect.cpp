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

			Frame Kinect::Connect()
			{
				return Frame();
			}

			Frame Kinect::Disconnect()
			{
				return Frame();
			}

			bool Kinect::HasFrame()
			{
				return false;
			}

			bool Kinect::IsConnected()
			{
				return false;
			}

			std::vector<std::shared_ptr<Data::Data>> Kinect::GetData()
			{
				// Get Kinect Frame

				// For each body					
				// Build Efficio Body

				// For each joint
				//Convert joint to Efficio Joint
				// Populate

				// Add Body to SkeletonData

				// Return data
				return std::vector<std::shared_ptr<Data::Data>>();
			}

			std::vector<std::shared_ptr<Events::Event>> Kinect::GetEvents()
			{
				return std::vector<std::shared_ptr<Events::Event>>();
			}
			void Kinect::PreGetFrame()
			{
			}
			void Kinect::PostGetFrame()
			{
			}
		}
	}
}