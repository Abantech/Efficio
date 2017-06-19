#include "LeapMotion.h"
#include "LeapMotionSensor.h"

namespace Efficio
{
	namespace Assets
	{
		LeapMotion::LeapMotion() 
		{
			LeapMotionSensor* sensor = new LeapMotionSensor();
			Asset::sensors.push_back(std::shared_ptr<Sensor>(sensor));
		}

		LeapMotion::~LeapMotion() { }
	}
}