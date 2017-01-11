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
	namespace Events
	{
		enum class DLLEXPORT EventType
		{
			EfficioStarted,
			SensorConnecting,
			SensorConnected,
			SensorDisconnecting,
			SensorDisconnected,
			SensorFaulted,
			Pinch,
			ButtonPressed
		};
	}
}