#include "SensorEvent.h"
namespace Efficio
{
	SensorEvent::SensorEvent(Efficio::SensorInformation details) : SensorInformation(details), DiscreteEvent(details.Name)
	{
	}
	SensorEvent::~SensorEvent()
	{
	}
}