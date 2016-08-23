#include "DeviceConfiguration.h"

namespace Efficio
{
	namespace Configuration
	{
		DeviceConfiguration::DeviceConfiguration()
		{
		}


		DeviceConfiguration::~DeviceConfiguration()
		{
		}

		LeapConfiguration DeviceConfiguration::GetLeapConfiguration()
		{
			return leapConfiguration;
		}

		void DeviceConfiguration::SetLeapConfiguration(LeapConfiguration configuration)
		{
			leapConfiguration = configuration;
		}

	}
}