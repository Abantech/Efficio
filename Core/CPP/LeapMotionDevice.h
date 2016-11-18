#pragma once

#include "Device.h"
#include <memory>
#include "Leap.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT LeapMotionDevice : public Efficio::Device {
	public:
		LeapMotionDevice(bool enabled = true);
		~LeapMotionDevice();
		Efficio::DeviceStatus Status();
		Efficio::TrackingType TrackingTypes();
		void Connect();
		void Disconnect();
		bool HasFrame();
		Efficio::Frame GetFrame();
	private:
		Leap::Controller* controller;
		Leap::Frame currentFrame;
		Leap::Frame lastFrame;
	};
}