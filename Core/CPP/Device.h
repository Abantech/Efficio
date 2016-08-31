#pragma once

#include "DeviceStatus.h"
#include "TrackingType.h"
#include "Vector3.h"
#include "Frame.h"
#include "Leap.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT Device
	{
	public:
		Device(bool enabled = true);
		~Device();
		int ID;
		Vector3 Position;
		Vector3 Direction;
		bool Enabled;
		bool Connected();
		virtual Efficio::DeviceStatus Status() = 0;
		virtual Efficio::TrackingType TrackingTypes() = 0;
		virtual void Connect() = 0;
		virtual void Disconnect() = 0;
		virtual bool HasFrame() = 0;
		virtual Leap::Frame GetFrame() = 0;
	};
}