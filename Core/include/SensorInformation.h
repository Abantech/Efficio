#pragma once

#include <string>

namespace Efficio
{
	namespace Sensors
	{
		class SensorInformation
		{
		public:
			SensorInformation();
			~SensorInformation();

			std::string Name;
			std::string Manufacturer;
			std::string SerialNumber;
			std::string FirmwareVersion;
			std::string AdditionalInformation;
		};
	}
}