#include "LeapMotionDevice.h"
#include <array>
#include <memory>
#include <iostream>

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
		//std::array<Efficio::Models::Human::Finger, 5> fingers;
		std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> fingers;
		Efficio::Body::BodySide side = hand.isLeft() ? Efficio::Body::BodySide::Left : Efficio::Body::BodySide::Right;
		

		for (size_t i = 0; i < 5; i++)
		{
			auto finger = CopyFinger(hand.fingers()[i]);

			std::shared_ptr<Efficio::Models::Human::Finger> fingerPtr(new Efficio::Models::Human::Finger(finger.Name, finger.Joints));
			fingers.push_back(fingerPtr);
		}

		Efficio::Models::Human::Hand effiCioHand(fingers, side);
		effiCioHand.IsLeftHand = hand.isLeft();

		return effiCioHand;
	}

	Efficio::Models::Human::Finger LeapMotionDevice::CopyFinger(Leap::Finger finger) {
		auto metacarpal = CopyJoint(Leap::Bone::Type::TYPE_METACARPAL, finger);
		auto proximal = CopyJoint(Leap::Bone::Type::TYPE_PROXIMAL, finger);
		auto intermediate = CopyJoint(Leap::Bone::Type::TYPE_INTERMEDIATE, finger);
		auto distal = CopyJoint(Leap::Bone::Type::TYPE_DISTAL, finger);

		//James' old code
		//std::map<Efficio::Models::Human::JointName, Efficio::Vector3> joints;
		//joints.emplace(metacarpal.Name, metacarpal.Position);
		//joints.emplace(proximal.Name, proximal.Position);
		//joints.emplace(intermediate.Name, intermediate.Position);
		//joints.emplace(distal.Name, distal.Position);
		
		std::vector<std::shared_ptr<Efficio::Models::Human::Joint>> joints;
		std::shared_ptr<Efficio::Models::Human::Joint> metacarpalJointPtr(new Efficio::Models::Human::Joint(metacarpal.Name, metacarpal.Position));
		std::shared_ptr<Efficio::Models::Human::Joint> proximalJointPtr(new Efficio::Models::Human::Joint(proximal.Name, proximal.Position));
		std::shared_ptr<Efficio::Models::Human::Joint> intermediateJointPtr(new Efficio::Models::Human::Joint(intermediate.Name, intermediate.Position));
		std::shared_ptr<Efficio::Models::Human::Joint> distalJointPtr(new Efficio::Models::Human::Joint(distal.Name, distal.Position));
		joints.push_back(metacarpalJointPtr);
		joints.push_back(proximalJointPtr);
		joints.push_back(intermediateJointPtr);
		joints.push_back(distalJointPtr);

		Efficio::Models::Human::FingerName fingerName;

		switch (finger.type())
		{
		case Leap::Finger::Type::TYPE_THUMB:
			fingerName = Efficio::Models::Human::FingerName::Thumb;
			break;
		case Leap::Finger::Type::TYPE_INDEX:
			fingerName = Efficio::Models::Human::FingerName::Index;
			break;
		case Leap::Finger::Type::TYPE_MIDDLE:
			fingerName = Efficio::Models::Human::FingerName::Middle;
			break;
		case Leap::Finger::Type::TYPE_RING:
			fingerName = Efficio::Models::Human::FingerName::Ring;
			break;
		case Leap::Finger::Type::TYPE_PINKY:
			fingerName = Efficio::Models::Human::FingerName::Pinky;
			break;
		}

		return Efficio::Models::Human::Finger(fingerName, joints);
	}

	Efficio::Models::Human::Joint LeapMotionDevice::CopyJoint(Leap::Bone::Type boneType, Leap::Finger finger)
	{
		Efficio::Models::Human::JointName jointName;
		auto jointPos = finger.bone(boneType).nextJoint();

		switch (boneType)
		{
		case Leap::Bone::TYPE_METACARPAL:
			jointName = Efficio::Models::Human::JointName::Metacarpal;
			break;
		case Leap::Bone::TYPE_PROXIMAL:
			jointName = Efficio::Models::Human::JointName::Proximal;
			break;
		case Leap::Bone::TYPE_INTERMEDIATE:
			jointName = Efficio::Models::Human::JointName::Intermediate;
			break;
		case Leap::Bone::TYPE_DISTAL:
			jointName = Efficio::Models::Human::JointName::Distal;
			break;
		default:
			break;
		}

		return Efficio::Models::Human::Joint(jointName, Vector3(jointPos.x, jointPos.y, jointPos.z));
	}
}