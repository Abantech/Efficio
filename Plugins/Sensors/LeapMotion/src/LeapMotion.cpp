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
			LeapMotion::LeapMotion() : connectionStateChanged(false)
			{
				Status = Sensors::Status::Uninitialized;
				controller.setPaused(true);
				SensorInformation.Name = "Leap Motion";
			}

			LeapMotion::~LeapMotion()
			{
			}

			Sensors::TrackingType LeapMotion::TrackingTypes()
			{
				return Sensors::TrackingType::Hand;
			}

			Frame LeapMotion::Connect()
			{
				Frame frame;
				controller.setPaused(false);
				connectionStateChanged = true;
				Status = Sensors::Status::Connecting;

				frame.AddEvent(std::shared_ptr<Events::Event>(new Sensors::Connecting(SensorInformation)));

				return frame;
			}

			Frame LeapMotion::Disconnect()
			{
				Frame frame;
				controller.setPaused(true);
				connectionStateChanged = true;

				frame.AddEvent(std::shared_ptr<Events::Event>(new Sensors::Disonnecting(SensorInformation)));

				return frame;
			}

			bool LeapMotion::HasFrame()
			{
				return controller.isConnected() && controller.frame().isValid() && controller.frame().id() != lastLeapFrame.id();
			}

			Efficio::Frame LeapMotion::GetFrame()
			{
				Efficio::Frame frame;

				if (connectionStateChanged)
				{
					if (controller.isConnected())
					{
						connectionStateChanged = false;
						hasConnected = true;
						frame.AddEvent(std::shared_ptr<Events::Event>(new Sensors::Connected(SensorInformation)));
						Status = Sensors::Status::Connected;
					}
					else
					{
						connectionStateChanged = false;
						frame.AddEvent(std::shared_ptr<Events::Event>(new Sensors::Disonnected(SensorInformation)));
						Status = Sensors::Status::Disconnected;
					}
				}

				// Check if new frame is available. If not, return previously calculated frame
				if (!HasFrame())
				{
					return LastEfficioFrame;
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

				frame.AddData(data);

				LastEfficioFrame = frame;

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

				Efficio::Models::Body::Hand efficioHand(side, efficioFingers, hand.confidence());
				efficioHand.ID = hand.id();

				return efficioHand;
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
						break;
					}
					case Leap::Finger::Type::TYPE_INDEX: {
						tipType = Efficio::Models::Body::JointType::LeftHandIndexTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandIndexDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandIndexMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandIndexPIP;
						fingerType = Efficio::Models::Body::FingerType::Index;
						break;
					}
					case Leap::Finger::Type::TYPE_MIDDLE: {
						tipType = Efficio::Models::Body::JointType::LeftHandMiddleTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandMiddleDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandMiddleMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandMiddlePIP;
						fingerType = Efficio::Models::Body::FingerType::Middle;
						break;
					}
					case Leap::Finger::Type::TYPE_RING: {
						tipType = Efficio::Models::Body::JointType::LeftHandRingTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandRingDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandRingMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandRingPIP;
						fingerType = Efficio::Models::Body::FingerType::Ring;
						break;
					}
					case Leap::Finger::Type::TYPE_PINKY: {
						tipType = Efficio::Models::Body::JointType::LeftHandPinkyTIP;
						dipType = Efficio::Models::Body::JointType::LeftHandPinkyDIP;
						mcpType = Efficio::Models::Body::JointType::LeftHandPinkyMCP;
						pipType = Efficio::Models::Body::JointType::LeftHandPinkyPIP;
						fingerType = Efficio::Models::Body::FingerType::Pinky;
						break;
					}
					}
				}
				else
				{
					switch (finger.type())
					{
					case Leap::Finger::Type::TYPE_THUMB: {
						tipType = Efficio::Models::Body::JointType::RightHandThumbTIP;
						dipType = Efficio::Models::Body::JointType::RightHandThumbIP;
						mcpType = Efficio::Models::Body::JointType::RightHandThumbMCP;
						pipType = Efficio::Models::Body::JointType::RightHandThumbCMP;
						fingerType = Efficio::Models::Body::FingerType::Thumb;
						break;
					}
					case Leap::Finger::Type::TYPE_INDEX: {
						tipType = Efficio::Models::Body::JointType::RightHandIndexTIP;
						dipType = Efficio::Models::Body::JointType::RightHandIndexDIP;
						mcpType = Efficio::Models::Body::JointType::RightHandIndexMCP;
						pipType = Efficio::Models::Body::JointType::RightHandIndexPIP;
						fingerType = Efficio::Models::Body::FingerType::Index;
						break;
					}
					case Leap::Finger::Type::TYPE_MIDDLE: {
						tipType = Efficio::Models::Body::JointType::RightHandMiddleTIP;
						dipType = Efficio::Models::Body::JointType::RightHandMiddleDIP;
						mcpType = Efficio::Models::Body::JointType::RightHandMiddleMCP;
						pipType = Efficio::Models::Body::JointType::RightHandMiddlePIP;
						fingerType = Efficio::Models::Body::FingerType::Middle;
						break;
					}
					case Leap::Finger::Type::TYPE_RING: {
						tipType = Efficio::Models::Body::JointType::RightHandRingTIP;
						dipType = Efficio::Models::Body::JointType::RightHandRingDIP;
						mcpType = Efficio::Models::Body::JointType::RightHandRingMCP;
						pipType = Efficio::Models::Body::JointType::RightHandRingPIP;
						fingerType = Efficio::Models::Body::FingerType::Ring;
						break;
					}
					case Leap::Finger::Type::TYPE_PINKY: {
						tipType = Efficio::Models::Body::JointType::RightHandPinkyTIP;
						dipType = Efficio::Models::Body::JointType::RightHandPinkyDIP;
						mcpType = Efficio::Models::Body::JointType::RightHandPinkyMCP;
						pipType = Efficio::Models::Body::JointType::RightHandPinkyPIP;
						fingerType = Efficio::Models::Body::FingerType::Pinky;
						break;
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