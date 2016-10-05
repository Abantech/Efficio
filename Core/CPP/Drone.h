#pragma once

#include "Asset.h"
#include "LocationSensor.h"
#include "Altimeter.h"
#include "Frame.h"

namespace Efficio
{
	namespace Models
	{
		/// A sample asset. A drone using the {@link Efficio::Sensors::SampleGPS} and the {@link Efficio::Sensors::SampleAltimeter}.
		extern class DLLEXPORT Drone : public Efficio::Asset {
		public:
			Drone();
			~Drone() {};

			Efficio::Frame GetFrame();
		};
	}
}