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
		extern class DLLEXPORT DeviceConfiguration
		{
		public:
			DeviceConfiguration();
			~DeviceConfiguration();
			LeapConfiguration GetLeapConfiguration();
			void SetLeapConfiguration(LeapConfiguration configuration);
		private:
			LeapConfiguration leapConfiguration;
		};
	}
}
