#pragma once

#include <string>

namespace Efficio
{
	/// Any sensor which can feed data into Efficio
	class Sensor
	{
	public:
		Sensor();
		~Sensor() {};

		// Virtual Methods
		/// The type of data the device is able to track
		virtual std::string Type() { return "type"; };

		/// The unique ID of the device
		std::string ID;

		/// A Boolean indicating whether or not the device is enabled
		bool Enabled;

		/// The status of the device
		std::string GetStatus();

		virtual std::string GetSource();

	private:
	};
}