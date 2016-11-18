#include "Device.h"
namespace Efficio {
	Device::Device(bool enabled) : Enabled(enabled), Position(0,0,0), Direction(0,0,0)
	{
	}

	Device::~Device()
	{
	}
	bool Device::Connected()
	{
		return Status() == DeviceStatus::Connected;
	}
}

