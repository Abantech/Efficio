#include "SensorEvent.h"
namespace Efficio
{
	namespace Sensors
	{
		SensorEvent::SensorEvent(Sensors::SensorInformation details): SensorInformation(details), Event(details.Name)
		{
		}
		SensorEvent::~SensorEvent()
		{
		}
	}
}