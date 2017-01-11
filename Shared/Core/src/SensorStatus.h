#pragma once

#if _WINDLL
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace Sensors
	{
		/// The device statii
		enum class DLLEXPORT Status 
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