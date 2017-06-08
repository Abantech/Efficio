#pragma once

#include <string>

namespace Efficio
{
	/// Contains information about the sensor
	class SensorInformation
	{
	public:
		SensorInformation();
		~SensorInformation();

		/// The name of the sensor
		std::string Name;

		/// The manufacturer of the sensor
		std::string Manufacturer;

		/// The serial number of the sensor
		std::string SerialNumber;

		/// The firmware version of the sensor
		std::string FirmwareVersion;

		/// Any additional information about the sensor
		std::string AdditionalInformation;
	};
}