#include "Sensor.h"
namespace Efficio
{
	namespace Sensors 
	{
		bool Efficio::Sensors::Sensor::Connected()
		{
			return GetStatus() == Status::Connected;
		}
		Status Sensor::GetStatus()
		{
			return Status;
		}
		std::string Sensor::GetSource()
		{
			return SensorInformation.Name;
		}
		SensorInformation Sensor::GetSensorInformation()
		{
			return SensorInformation;
		}
	}
}