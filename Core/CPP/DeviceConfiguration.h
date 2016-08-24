#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include "LeapConfiguration.h"

namespace Efficio
{
	namespace Configuration
	{
		/// The device configuration is used to configure the devices with which Efficio can work.
		extern class DLLEXPORT DeviceConfiguration
		{
		public:
			DeviceConfiguration();
			~DeviceConfiguration();

			/// The configuration for the Leap Motion
			LeapConfiguration LeapConfiguration;
		};
	}
}
