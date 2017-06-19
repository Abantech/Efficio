#pragma once

#include <memory>
#include "Sensor.h"

namespace Efficio
{
	/// The base for any object within the Efficio system
	class Asset
	{
	public:
		Asset();
		~Asset();

		/// Gets the sensors attached to asset
		std::vector<std::shared_ptr<Sensor>> GetSensors();

	protected:
		std::vector<std::shared_ptr<Sensor>> sensors;
	};
}