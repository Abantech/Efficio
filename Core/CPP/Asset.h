#pragma once

#include <string>
#include <vector>
#include "Sensor.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// The most basic object in the Efficio system.
	extern class DLLEXPORT Asset {

	public:
		/// The unique ID of the asset
		int ID;

		/// The friendly name of the asset
		std::string FriendlyName;

		/// The description of the asset
		std::string Description;

		/// The sensors attached to the asset.
		std::vector<Efficio::Sensors::Sensor*> Sensors;

		/// Gets the current frame from the device
		virtual Efficio::Frame GetFrame() = 0;
	};
}