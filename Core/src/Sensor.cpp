#include "Sensor.h"
namespace Efficio
{
	namespace Sensors 
	{
		bool Efficio::Sensors::Sensor::Connected()
		{
			return Status() == Status::Connected;
		}
	}
}