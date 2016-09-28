#include "DeviceManager.h"
namespace Efficio {
	DeviceManager::DeviceManager()
	{
	}

	DeviceManager::~DeviceManager()
	{
	}

	void DeviceManager::AddDevice(std::shared_ptr<Efficio::Device> device)
	{
		devices.push_back(device);
	}

	std::vector<std::shared_ptr<Efficio::Device>> DeviceManager::GetDevices()
	{
		return devices;
	}

	std::vector<std::shared_ptr<Efficio::Device>> DeviceManager::GetConnectedDevices()
	{
		return GetDevicesWithStatus(Efficio::DeviceStatus::Connected);
	}

	std::vector<std::shared_ptr<Efficio::Device>> DeviceManager::GetDevicesWithStatus(Efficio::DeviceStatus status)
	{
		std::vector<std::shared_ptr<Efficio::Device>> devicesWithStatus;

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i]->Status() == status)
			{
				devicesWithStatus.push_back(devices[i]);
			}
		}

		return devicesWithStatus;
	}

	std::shared_ptr<Efficio::Device> DeviceManager::GetDeviceByID(std::string ID)
	{
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i]->ID == ID)
			{
				return devices[i];
			}
		}

		return std::shared_ptr<Efficio::Device>();
	}

	void DeviceManager::RemoveDevice(std::string ID)
	{
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i]->ID == ID)
			{
				devices.erase(devices.begin() + i);
			}
		}
	}
}