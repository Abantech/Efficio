#pragma once

#include <vector>
#include <memory>

#include "Device.h"
#include "DeviceStatus.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Manages all the devices connected to Efficio
	extern class DLLEXPORT DeviceManager {
	public:
		DeviceManager();
		~DeviceManager();

		/// Adds a device to Efficio
		void AddDevice(std::shared_ptr<Efficio::Device>  device);

		/// Gets all the registered devices
		std::vector<std::shared_ptr<Efficio::Device>> GetDevices();

		/// Gets all the connected devices
		std::vector<std::shared_ptr<Efficio::Device>> GetConnectedDevices();

		/// Gets all the devices with a matching status
		std::vector<std::shared_ptr<Efficio::Device>> GetDevicesWithStatus(Efficio::DeviceStatus status);

		/// Gets a device by ID
		std::shared_ptr<Efficio::Device> GetDeviceByID(std::string ID);

		/// Removes a device by ID
		void RemoveDevice(std::string ID);
	private:
		std::vector<std::shared_ptr<Efficio::Device>> devices;
	};
}