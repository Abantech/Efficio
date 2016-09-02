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
		Efficio::Models::Human::Hand CopyHand(Leap::Hand hand);
		Efficio::Models::Human::Finger CopyFinger(Efficio::Body::BodySide side, Leap::Finger finger);
		Efficio::Models::Human::Joint CopyJoint(Leap::Bone::Type boneType, Leap::Finger finger);
		Efficio::Models::Human::Bone2 CreateFingerBone(Efficio::Body::BodySide bodySide, std::string fingerStringName, Efficio::Models::Human::Joint* startJoint, Efficio::Models::Human::Joint* endJoint);
	};
}