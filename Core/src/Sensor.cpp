#include "..\include\Sensor.h"

namespace Efficio {
	Sensor::Sensor()
	{
	}

	std::string Sensor::GetSource()
	{
		return "source";
	}

	std::string Sensor::GetStatus() {
		return "status";
	}
}
