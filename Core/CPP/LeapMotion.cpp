#include "LeapMotion.h"
#include "Finger.h"
#include "Joint.h"
#include "HandData.h"
#include <vector>
#include <array>
#include <memory>

namespace Efficio
{
	namespace Sensors
	{
		namespace Body
		{
			LeapMotion::LeapMotion()
			{
				controller.setPaused(true);
			}

			LeapMotion::~LeapMotion()
			{
			}

			Efficio::DeviceStatus LeapMotion::Status()
			{
				return Efficio::DeviceStatus();
			}

			Efficio::TrackingType LeapMotion::TrackingTypes()
			{
				return Efficio::TrackingType();
			}

			void LeapMotion::Connect()
			{
				controller.setPaused(false);
			}

			void LeapMotion::Disconnect()
			{
				controller.setPaused(true);
			}

			bool LeapMotion::HasFrame()
			{
				return controller.isConnected() && controller.frame().isValid() && controller.frame().id() != lastLeapFrame.id();
			}

			Efficio::Frame LeapMotion::GetFrame()
			{
				// Check if new frame is available. If not, return previously calculated frame
				if (!HasFrame())
				{
					return lastEfficioFrame;
				}

				// Poll for latest Leap Motion frame
				lastLeapFrame = controller.frame();


				// Convert Leap hands to Efficio hands
				auto hands = lastLeapFrame.hands();

				std::vector<Efficio::Models::Body::Hand> convertedHands;

				for (size_t i = 0; i < hands.count(); i++)
				{
					convertedHands.push_back(convertToEfficioHand(hands[i]));
				}

				std::vector<std::shared_ptr<Efficio::Data::Data>> data;
				
				std::shared_ptr<Efficio::Data::Data> dataSharedPtr(new Efficio::Data::Body::HandData(convertedHands));

				data.push_back(dataSharedPtr);

				Efficio::Frame frame;

				frame.AddData(data);

				return frame;
			}

	
			Efficio::Models::Body::Hand LeapMotion::convertToEfficioHand(Leap::Hand hand)
			{
				auto fingers = hand.fingers();

				std::array<Efficio::Models::Body::Finger, 5> efficioFingers =
				{
					convertToEfficioFinger(fingers[0]),
					convertToEfficioFinger(fingers[1]),
					convertToEfficioFinger(fingers[2]),
					convertToEfficioFinger(fingers[3]),
					convertToEfficioFinger(fingers[4])
				};

				auto side = hand.isLeft() ? Efficio::Models::Body::BodySide::Left : Efficio::Models::Body::BodySide::Right;

				return Efficio::Models::Body::Hand(side, efficioFingers);
			}

			Efficio::Models::Body::Finger LeapMotion::convertToEfficioFinger(Leap::Finger finger)
			{
				auto tipPosition = finger.jointPosition(Leap::Finger::JOINT_TIP);
				auto dipPosition = finger.jointPosition(Leap::Finger::JOINT_DIP);
				auto mcpPosition = finger.jointPosition(Leap::Finger::JOINT_MCP);
				auto pipPosition = finger.jointPosition(Leap::Finger::JOINT_PIP);

				Efficio::Models::Body::JointType tipType;
				Efficio::Models::Body::JointType dipType;
				Efficio::Models::Body::JointType mcpType;
				Efficio::Models::Body::JointType pipType;
				Efficio::Models::Body::FingerType fingerType;

				if (finger.hand().isLeft())
				{
					switch (finger.type())
					{
					case Leap::Finger::Type::TYPE_THUMB: {
						//TOD Correct this mapping
						tipType = Efficio::Models::Body::JointType::LeftHandThumbTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandThumbIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandThumbMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandThumbCMP;
						fingerType = Efficio::Models::Body::FingerType::Thumb;
					}
					case Leap::Finger::Type::TYPE_INDEX: {
						tipType = Efficio::Models::Body::JointType::LeftHandIndexTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandIndexDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandIndexMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandIndexPIP;
						fingerType = Efficio::Models::Body::FingerType::Index;
					}
					case Leap::Finger::Type::TYPE_MIDDLE: {
						tipType = Efficio::Models::Body::JointType::LeftHandMiddleTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandMiddleDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandMiddleMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandMiddlePIP;
						fingerType = Efficio::Models::Body::FingerType::Middle;
					}
					case Leap::Finger::Type::TYPE_RING: {
						tipType = Efficio::Models::Body::JointType::LeftHandRingTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandRingDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandRingMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandRingPIP;
						fingerType = Efficio::Models::Body::FingerType::Ring;
					}
					case Leap::Finger::Type::TYPE_PINKY: {
						tipType = Efficio::Models::Body::JointType::LeftHandPinkyTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandPinkyDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandPinkyMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandPinkyPIP;
						fingerType = Efficio::Models::Body::FingerType::Pinky;
					}
					}
				}
				else
				{
					switch (finger.type())
					{
					case Leap::Finger::Type::TYPE_THUMB: {
						//TOD Correct this mapping
						tipType = Efficio::Models::Body::JointType::LeftHandThumbTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandThumbIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandThumbMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandThumbCMP;
						fingerType = Efficio::Models::Body::FingerType::Thumb;
					}
					case Leap::Finger::Type::TYPE_INDEX: {
						tipType = Efficio::Models::Body::JointType::LeftHandIndexTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandIndexDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandIndexMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandIndexPIP;
						fingerType = Efficio::Models::Body::FingerType::Index;
					}
					case Leap::Finger::Type::TYPE_MIDDLE: {
						tipType = Efficio::Models::Body::JointType::LeftHandMiddleTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandMiddleDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandMiddleMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandMiddlePIP;
						fingerType = Efficio::Models::Body::FingerType::Middle;
					}
					case Leap::Finger::Type::TYPE_RING: {
						tipType = Efficio::Models::Body::JointType::LeftHandRingTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandRingDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandRingMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandRingPIP;
						fingerType = Efficio::Models::Body::FingerType::Ring;
					}
					case Leap::Finger::Type::TYPE_PINKY: {
						tipType = Efficio::Models::Body::JointType::LeftHandPinkyTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandPinkyDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandPinkyMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandPinkyPIP;
						fingerType = Efficio::Models::Body::FingerType::Pinky;
					}
					}
				}

				auto tipJoint = Efficio::Models::Body::Joint(Vector3(tipPosition.x, tipPosition.y, tipPosition.z), tipType);
				auto dipJoint = Efficio::Models::Body::Joint(Vector3(dipPosition.x, dipPosition.y, dipPosition.z), dipType);
				auto mcpJoint = Efficio::Models::Body::Joint(Vector3(mcpPosition.x, mcpPosition.y, mcpPosition.z), mcpType);
				auto pipJoint = Efficio::Models::Body::Joint(Vector3(pipPosition.x, pipPosition.y, pipPosition.z), pipType);

				return Efficio::Models::Body::Finger(fingerType, finger.isExtended(), finger.length(), tipJoint, dipJoint, mcpJoint, pipJoint);
			}
		}
	}
}