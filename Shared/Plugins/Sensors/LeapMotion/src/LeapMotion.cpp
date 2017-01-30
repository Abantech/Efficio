# define M_PI           3.14159265358979323846  /* pi */

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
				// Call base class disconnect
				auto frame = Sensor::Connect();

				// Set Leap Motion to unpaused
				controller.setPaused(false);

				// Add additional frame information here

				return frame;
			}

			Frame LeapMotion::Disconnect()
			{
				// Call base class disconnect
				auto frame = Sensor::Disconnect();
				
				// Set Leap Motion to pause
				controller.setPaused(true);

				// Add additional frame information here

				return frame;
			}

			bool LeapMotion::IsConnected() 
			{
				return controller.isConnected();
			}

			std::vector<std::shared_ptr<Events::Event>> LeapMotion::GetEvents()
			{
				return std::vector<std::shared_ptr<Events::Event>>();
			}

			bool LeapMotion::HasFrame()
			{
				return controller.isConnected() && controller.frame().isValid() && latestLeapFrame.id() != lastLeapFrameID;
			}

			void LeapMotion::PreGetFrame()
			{
				// Poll for latest Leap Motion frame
				latestLeapFrame = controller.frame();
			}

			void LeapMotion::PostGetFrame()
			{
				// Set last frame ID to latest frame pulled
				lastLeapFrameID = latestLeapFrame.id();
			}

			std::vector<std::shared_ptr<Data::Data>> LeapMotion::GetData()
			{
				std::vector<std::shared_ptr<Data::Data>> data;
				
				auto dataSharedPtr = std::make_shared<Efficio::Data::Body::HandData>(GetHandData());

				data.push_back(dataSharedPtr);

				return data;
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

				// Calculate Supine Angle
				auto inverter = hand.isLeft() ? 1 : -1;
				efficioHand.SupinationAngle = hand.palmNormal().roll() * (180 / M_PI) * inverter;

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

			void LeapMotion::EnableHandTracking(bool enable)
			{
			}

			Data::Body::HandData LeapMotion::GetHandData()
			{
				// Convert Leap hands to Efficio hands
				auto hands = latestLeapFrame.hands();

				std::vector<Efficio::Models::Body::Hand> convertedHands;

				for (size_t i = 0; i < hands.count(); i++)
				{
					convertedHands.push_back(convertToEfficioHand(hands[i]));
				}

				return Data::Body::HandData(convertedHands);
			}
		}
	}
}