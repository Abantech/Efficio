#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		/// The device statii
		extern enum class DLLEXPORT Status 
		{
			Unknown,
			Uninitialized,
			Disabled,
			Faulted,
			Disconnecting,
			Disconnected,
			Connecting,
			Connected
		};
	}
}