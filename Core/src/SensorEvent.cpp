#include "SensorEvent.h"
namespace Efficio
{
	SensorEvent::SensorEvent(Efficio::SensorInformation details) : SensorInformation(details), Event(details.Name)
	{
	}
	SensorEvent::~SensorEvent()
	{
	}
}