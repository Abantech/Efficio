#include "LeapMotionDevice.h"
#include <array>

namespace Efficio
{
	LeapMotionDevice::LeapMotionDevice(bool enabled) : Device(enabled)
	{
		if (Enabled)
		{
			controller = new Leap::Controller();
			controller->setPaused(true);
			ID = controller->devices()[0].serialNumber();
		}
	}

	LeapMotionDevice::~LeapMotionDevice()
	{
		delete controller;
	}

	Efficio::DeviceStatus LeapMotionDevice::Status()
	{
		Efficio::DeviceStatus status = DeviceStatus::Unknown;

		if (!Enabled)
		{
			status = Efficio::DeviceStatus::Disabled;
		}
		else
		{
			if (!controller)
			{
				status = Efficio::DeviceStatus::Faulted;
			}
			else
			{
				if (controller->isPaused())
				{
					status = Efficio::DeviceStatus::Disconnected;
				}
				else
				{
					status = Efficio::DeviceStatus::Connected;
				}
			}
		}

		return status;
	}

	Efficio::TrackingType LeapMotionDevice::TrackingTypes()
	{
		return Efficio::TrackingType::Hand;
	}

	void LeapMotionDevice::Connect()
	{
		if (Enabled)
		{
			controller->setPaused(false);
		}
	}

	void LeapMotionDevice::Disconnect()
	{
		if (Enabled)
		{
			controller->setPaused(true);
		}
	}

	bool LeapMotionDevice::HasFrame()
	{
		bool sameFrame = true;

		if (Enabled)
		{
			currentFrame = controller->frame();

			sameFrame = currentFrame.id() == lastFrame.id();

			lastFrame = currentFrame;
		}

		return sameFrame;
	}

	Efficio::Frame LeapMotionDevice::GetFrame()
	{
		Efficio::Frame frame;

		if (Enabled)
		{
			auto leapFrame = controller->frame();

			if (leapFrame.isValid())
			{
				if (leapFrame.hands().count() > 0)
				{
					HandData handData;

					for each (Leap::Hand hand in leapFrame.hands())
					{
						handData.Hands.push_back(CopyHand(hand));
					}

					frame.HandData = handData;
				}
			}
		}

		return frame;
	}

	Efficio::Models::Human::Hand LeapMotionDevice::CopyHand(Leap::Hand hand) {
		std::array<Efficio::Models::Human::Finger, 5> fingers;

		Efficio::Body::BodySide side = hand.isLeft() ? Efficio::Body::BodySide::Left : Efficio::Body::BodySide::Right;

		for (size_t i = 0; i < 5; i++)
		{
			auto finger = CopyFinger(side, hand.fingers()[i]);
			fingers.at(i) = finger;
			
		}
		return Efficio::Models::Human::Hand(fingers, side);
	}

	Efficio::Models::Human::Finger LeapMotionDevice::CopyFinger(Efficio::Body::BodySide side, Leap::Finger finger) {
		auto metacarpal = CopyJoint(Leap::Bone::Type::TYPE_METACARPAL, finger);
		auto proximal = CopyJoint(Leap::Bone::Type::TYPE_PROXIMAL, finger);
		auto intermediate = CopyJoint(Leap::Bone::Type::TYPE_INTERMEDIATE, finger);
		auto distal = CopyJoint(Leap::Bone::Type::TYPE_DISTAL, finger);

		std::map<std::string, Efficio::Vector3> joints;

		joints.emplace(metacarpal.Name, metacarpal.Position);
		joints.emplace(proximal.Name, proximal.Position);
		joints.emplace(intermediate.Name, intermediate.Position);
		joints.emplace(distal.Name, distal.Position);

		Efficio::Models::Human::FingerName fingerName;
		std::string fingerStringName;

		switch (finger.type())
		{
		case Leap::Finger::Type::TYPE_THUMB:
			fingerName = Efficio::Models::Human::FingerName::Thumb;
			fingerStringName = "Thumb";
			break;
		case Leap::Finger::Type::TYPE_INDEX:
			fingerName = Efficio::Models::Human::FingerName::Index;
			fingerStringName = "Index";
			break;
		case Leap::Finger::Type::TYPE_MIDDLE:
			fingerName = Efficio::Models::Human::FingerName::Middle;
			fingerStringName = "Middle";
			break;
		case Leap::Finger::Type::TYPE_RING:
			fingerName = Efficio::Models::Human::FingerName::Ring;
			fingerStringName = "Ring";
			break;
		case Leap::Finger::Type::TYPE_PINKY:
			fingerName = Efficio::Models::Human::FingerName::Pinky;
			fingerStringName = "Pinky";
			break;
		}

		Efficio::Models::Human::Finger efficiofinger = Efficio::Models::Human::Finger(fingerName, joints);
		auto proximalBone = CreateFingerBone(side, fingerStringName, &metacarpal, &proximal);
		auto intermediateBone = CreateFingerBone(side, fingerStringName, &proximal, &intermediate);
		auto distalBone = CreateFingerBone(side, fingerStringName, &proximal, &distal);

		efficiofinger.Bones.emplace(proximalBone.Name, proximalBone);
		efficiofinger.Bones.emplace(intermediateBone.Name, intermediateBone);
		efficiofinger.Bones.emplace(distalBone.Name, distalBone);

		return efficiofinger;
	}

	Efficio::Models::Human::Bone2 LeapMotionDevice::CreateFingerBone(Efficio::Body::BodySide bodySide, std::string fingerStringName, Efficio::Models::Human::Joint* startJoint, Efficio::Models::Human::Joint* endJoint)
	{
		std::string boneName(bodySide == Efficio::Body::BodySide::Left ? "LeftHand" : "RightHand");
		boneName.append("-");
		boneName.append(fingerStringName);
		boneName.append("-");
		boneName.append(startJoint->Name);
		boneName.append("-");
		boneName.append(endJoint->Name);

		return Efficio::Models::Human::Bone2(boneName, startJoint, endJoint);
	}

	Efficio::Models::Human::Joint LeapMotionDevice::CopyJoint(Leap::Bone::Type boneType, Leap::Finger finger)
	{
		std::string jointName;
		auto jointPos = finger.bone(boneType).nextJoint();

		switch (boneType)
		{
		case Leap::Bone::TYPE_METACARPAL:
			jointName = "Metacarpal";
			break;
		case Leap::Bone::TYPE_PROXIMAL:
			jointName = "Proximal";
			break;
		case Leap::Bone::TYPE_INTERMEDIATE:
			jointName = "Intermediate";
			break;
		case Leap::Bone::TYPE_DISTAL:
			jointName = "Distal";
			break;
		default:
			break;
		}

		return Efficio::Models::Human::Joint(jointName, Vector3(jointPos.x, jointPos.y, jointPos.z));
	}
}