#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// The device statii
	extern enum class DLLEXPORT DeviceStatus {
		Unknown,
		Disabled,
		Faulted,
		Disconnected,
		Connecting,
		Connected
	};
}