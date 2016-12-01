#include "Kinect.h"

namespace Efficio
{
	namespace Sensors
	{
		namespace Body
		{
			Kinect::Kinect()
			{
			}

			Kinect::~Kinect()
			{
			}

			Sensors::Status Kinect::Status()
			{
				return Sensors::Status::Unknown;
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

			Frame Kinect::GetFrame()
			{
				return Frame();
			}

			std::string Kinect::GetSource()
			{
				return "Microsoft Kinect";
			}
		}
	}
}