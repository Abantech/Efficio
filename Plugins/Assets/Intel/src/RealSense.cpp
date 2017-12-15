#include "RealSense.h"
#include "RealSenseSensor.h"

namespace Efficio
{
	namespace Assets
	{
		RealSense::RealSense()
		{
			RealSenseSensor* sensor = new RealSenseSensor();
			sensor->EnableHandTracking(true);
			sensor->EnableImageTracking(false);
			Asset::sensors.push_back(std::shared_ptr<Sensor>(sensor));
		}

		RealSense::~RealSense() { }
	}
}