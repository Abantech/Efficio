#pragma once

#include <string>

namespace Efficio
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