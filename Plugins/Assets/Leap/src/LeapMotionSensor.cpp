# define M_PI           3.14159265358979323846  /* pi */

#include "LeapMotionSensor.h"
#include "Finger.h"
#include "Joint.h"
#include "HandData.h"
#include <vector>
#include <array>
#include <memory>

namespace Efficio
{
	namespace Assets
	{
		LeapMotionSensor::LeapMotionSensor()
		{
			controller.setPaused(true);
			SensorInformation.Name = "Leap Motion";
		}

		LeapMotionSensor::~LeapMotionSensor()
		{
		}

		std::string LeapMotionSensor::TrackingType()
		{
			return "Hand";
		}

		Frame LeapMotionSensor::Connect()
		{
			// Call base class disconnect
			auto frame = Sensor::Connect();

			// Set Leap Motion to unpaused
			controller.setPaused(false);

			// Add additional frame information here
			return frame;
		}

		Frame LeapMotionSensor::Disconnect()
		{
			// Call base class disconnect
			auto frame = Sensor::Disconnect();

			// Set Leap Motion to pause
			controller.setPaused(true);

			// Add additional frame information here

			return frame;
		}

		bool LeapMotionSensor::IsConnected()
		{
			return controller.isConnected();
		}

		std::vector<std::shared_ptr<Event>> LeapMotionSensor::GetEvents()
		{
			return std::vector<std::shared_ptr<Event>>();
		}

		bool LeapMotionSensor::HasFrame()
		{
			return IsConnected() && controller.frame().isValid() && latestLeapFrame.id() != lastLeapFrameID;
		}

		void LeapMotionSensor::PreGetFrame()
		{
			// Poll for latest Leap Motion frame
			latestLeapFrame = controller.frame();
		}

		void LeapMotionSensor::PostGetFrame()
		{
			// Set last frame ID to latest frame pulled
			lastLeapFrameID = latestLeapFrame.id();
		}

		std::vector<std::shared_ptr<Data>> LeapMotionSensor::GetData()
		{
			std::vector<std::shared_ptr<Data>> data;

			if (trackingHands)
			{
				auto dataSharedPtr = std::make_shared<Models::Body::HandData>(GetHandData());
				data.push_back(dataSharedPtr);
			}

			if (trackingImages)
			{
				controller.setPolicy(Leap::Controller::POLICY_IMAGES);
				auto dataSharedPtr = std::make_shared<Models::AudioVisual::ImageData>(GetImageData());
				data.push_back(dataSharedPtr);
			}

			return data;
		}

		Models::Body::Hand LeapMotionSensor::convertToEfficioHand(Leap::Hand hand)
		{
			auto fingers = hand.fingers();

			std::array<Models::Body::Finger, 5> efficioFingers =
			{
				convertToEfficioFinger(fingers[0]),
				convertToEfficioFinger(fingers[1]),
				convertToEfficioFinger(fingers[2]),
				convertToEfficioFinger(fingers[3]),
				convertToEfficioFinger(fingers[4])
			};

			auto side = hand.isLeft() ? Models::Body::BodySide::Left : Models::Body::BodySide::Right;

			Models::Body::Hand efficioHand(side, efficioFingers, hand.confidence());
			efficioHand.ID = hand.id();
			efficioHand.Source = GetSensorInformation().Name;

			return efficioHand;
		}

		Models::Body::Finger LeapMotionSensor::convertToEfficioFinger(Leap::Finger finger)
		{
			auto tipPosition = finger.jointPosition(Leap::Finger::JOINT_TIP);
			auto dipPosition = finger.jointPosition(Leap::Finger::JOINT_DIP);
			auto mcpPosition = finger.jointPosition(Leap::Finger::JOINT_MCP);
			auto pipPosition = finger.jointPosition(Leap::Finger::JOINT_PIP);

			Models::Body::JointType tipType;
			Models::Body::JointType dipType;
			Models::Body::JointType mcpType;
			Models::Body::JointType pipType;
			Models::Body::FingerType fingerType;

			if (finger.hand().isLeft())
			{
				switch (finger.type())
				{
				case Leap::Finger::Type::TYPE_THUMB: {
					//TOD Correct this mapping
					tipType = Models::Body::JointType::LeftHandThumbTIP;
					dipType = Models::Body::JointType::LeftHandThumbDIP;
					mcpType = Models::Body::JointType::LeftHandThumbMCP;
					pipType = Models::Body::JointType::LeftHandThumbCMP;
					fingerType = Models::Body::FingerType::Thumb;
					break;
				}
				case Leap::Finger::Type::TYPE_INDEX: {
					tipType = Models::Body::JointType::LeftHandIndexTIP;
					dipType = Models::Body::JointType::LeftHandIndexDIP;
					mcpType = Models::Body::JointType::LeftHandIndexMCP;
					pipType = Models::Body::JointType::LeftHandIndexPIP;
					fingerType = Models::Body::FingerType::Index;
					break;
				}
				case Leap::Finger::Type::TYPE_MIDDLE: {
					tipType = Models::Body::JointType::LeftHandMiddleTIP;
					dipType = Models::Body::JointType::LeftHandMiddleDIP;
					mcpType = Models::Body::JointType::LeftHandMiddleMCP;
					pipType = Models::Body::JointType::LeftHandMiddlePIP;
					fingerType = Models::Body::FingerType::Middle;
					break;
				}
				case Leap::Finger::Type::TYPE_RING: {
					tipType = Models::Body::JointType::LeftHandRingTIP;
					dipType = Models::Body::JointType::LeftHandRingDIP;
					mcpType = Models::Body::JointType::LeftHandRingMCP;
					pipType = Models::Body::JointType::LeftHandRingPIP;
					fingerType = Models::Body::FingerType::Ring;
					break;
				}
				case Leap::Finger::Type::TYPE_PINKY: {
					tipType = Models::Body::JointType::LeftHandPinkyTIP;
					dipType = Models::Body::JointType::LeftHandPinkyDIP;
					mcpType = Models::Body::JointType::LeftHandPinkyMCP;
					pipType = Models::Body::JointType::LeftHandPinkyPIP;
					fingerType = Models::Body::FingerType::Pinky;
					break;
				}
				}
			}
			else
			{
				switch (finger.type())
				{
				case Leap::Finger::Type::TYPE_THUMB: {
					tipType = Models::Body::JointType::RightHandThumbTIP;
					dipType = Models::Body::JointType::RightHandThumbDIP;
					mcpType = Models::Body::JointType::RightHandThumbMCP;
					pipType = Models::Body::JointType::RightHandThumbCMP;
					fingerType = Models::Body::FingerType::Thumb;
					break;
				}
				case Leap::Finger::Type::TYPE_INDEX: {
					tipType = Models::Body::JointType::RightHandIndexTIP;
					dipType = Models::Body::JointType::RightHandIndexDIP;
					mcpType = Models::Body::JointType::RightHandIndexMCP;
					pipType = Models::Body::JointType::RightHandIndexPIP;
					fingerType = Models::Body::FingerType::Index;
					break;
				}
				case Leap::Finger::Type::TYPE_MIDDLE: {
					tipType = Models::Body::JointType::RightHandMiddleTIP;
					dipType = Models::Body::JointType::RightHandMiddleDIP;
					mcpType = Models::Body::JointType::RightHandMiddleMCP;
					pipType = Models::Body::JointType::RightHandMiddlePIP;
					fingerType = Models::Body::FingerType::Middle;
					break;
				}
				case Leap::Finger::Type::TYPE_RING: {
					tipType = Models::Body::JointType::RightHandRingTIP;
					dipType = Models::Body::JointType::RightHandRingDIP;
					mcpType = Models::Body::JointType::RightHandRingMCP;
					pipType = Models::Body::JointType::RightHandRingPIP;
					fingerType = Models::Body::FingerType::Ring;
					break;
				}
				case Leap::Finger::Type::TYPE_PINKY: {
					tipType = Models::Body::JointType::RightHandPinkyTIP;
					dipType = Models::Body::JointType::RightHandPinkyDIP;
					mcpType = Models::Body::JointType::RightHandPinkyMCP;
					pipType = Models::Body::JointType::RightHandPinkyPIP;
					fingerType = Models::Body::FingerType::Pinky;
					break;
				}
				}
			}

			auto tipJoint = Models::Body::Joint(Vector3(tipPosition.x, tipPosition.y, tipPosition.z), tipType);
			auto dipJoint = Models::Body::Joint(Vector3(dipPosition.x, dipPosition.y, dipPosition.z), dipType);
			auto mcpJoint = Models::Body::Joint(Vector3(mcpPosition.x, mcpPosition.y, mcpPosition.z), mcpType);
			auto pipJoint = Models::Body::Joint(Vector3(pipPosition.x, pipPosition.y, pipPosition.z), pipType);

			return Models::Body::Finger(fingerType, finger.isExtended(), finger.length(), tipJoint, dipJoint, mcpJoint, pipJoint);
		}

		void LeapMotionSensor::EnableHandTracking(bool enable)
		{
			trackingHands = enable;
		}

		void LeapMotionSensor::EnableImageTracking(bool enable)
		{
			trackingImages = enable;
		}

		Models::Body::HandData LeapMotionSensor::GetHandData()
		{
			// Convert Leap hands to Efficio hands
			auto hands = latestLeapFrame.hands();

			std::vector<Models::Body::Hand> convertedHands;

			for (int i = 0; i < hands.count(); i++)
			{
				convertedHands.push_back(convertToEfficioHand(hands[i]));
			}

			return Models::Body::HandData(convertedHands);
		}

		Models::AudioVisual::ImageData LeapMotionSensor::GetImageData()
		{
			Models::AudioVisual::ImageData data;

			Leap::ImageList images = latestLeapFrame.images();
			for (int i = 0; i < 2; i++) {
				Leap::Image image = images[i];

				const unsigned char* image_buffer = image.data();
				data.Images.push_back(Models::AudioVisual::Image(image.height(), image.width(), image.bytesPerPixel(), image_buffer));
			}

			return data;
		}
	}
}