#include "Engine.h"
#include <iostream>
#include "Enumerations.h"
#include "Vector3.h"
#include  "Leap.h"


namespace Efficio {
	Engine::Engine() : started(false), frameID(1)
	{
	}

	Engine::~Engine()
	{
		controller->~Controller();
	}

	void Engine::Start()
	{
		if (DeviceConfiguration.LeapConfiguration.Enabled)
		{
			controller = new Leap::Controller();
		}

		started = true;
	}

	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame()
	{
		std::shared_ptr<Efficio::EfficioFrame> efficioFrame(new EfficioFrame(frameID++));

		if (started)
		{
			if (controller != 0)
			{
				auto frame = controller->frame();

				if (frame.isValid())
				{
					auto hands = frame.hands();

					if (hands.count() > 0)
					{
						for (size_t i = 0; i < hands.count(); i++)
						{
							Efficio::Body::Hand EHand = Efficio::Body::Hand();
							vector<shared_ptr<Efficio::Body::Finger>> handFingers = vector<shared_ptr<Efficio::Body::Finger>>();
							auto hand = hands[i];
							for (int f = 0; f < hand.fingers().count(); f++)
							{
								switch (hands[i].fingers()[f].type()) {
								case Leap::Finger::TYPE_THUMB: {

									Efficio::Body::Finger thumb = Efficio::Body::Finger(Efficio::Body::FingerType::Thumb);

									//shared_ptr purpose is to optimize memory use, non-agenda topping

									Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
									FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
									DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

									Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
									FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
									DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

									Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
									FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
									DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

									EHand.Fingers.push_back(make_shared<Efficio::Body::Finger>(thumb));

									break;
								}
								case Leap::Finger::TYPE_INDEX:
								{
									Efficio::Body::Finger index = Efficio::Body::Finger(Efficio::Body::FingerType::Index);

									Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
									FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
									DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

									Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
									FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
									DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

									Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
									FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
									DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

									EHand.Fingers.push_back(make_shared<Efficio::Body::Finger>(index));

									break;
								}
								case Leap::Finger::TYPE_MIDDLE:
								{
									Efficio::Body::Finger middle = Efficio::Body::Finger(Efficio::Body::FingerType::Middle);

									Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
									FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
									DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

									Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
									FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
									DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

									Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
									FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
									DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

									EHand.Fingers.push_back(make_shared<Efficio::Body::Finger>(middle));

									break;
								}
								case Leap::Finger::TYPE_RING:
								{
									Efficio::Body::Finger ring = Efficio::Body::Finger(Efficio::Body::FingerType::Ring);

									Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
									FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
									DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

									Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
									FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
									DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

									Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
									FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
									DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

									EHand.Fingers.push_back(make_shared<Efficio::Body::Finger>(ring));

									break;
								}
								case Leap::Finger::TYPE_PINKY:
								{
									Efficio::Body::Finger pinky = Efficio::Body::Finger(Efficio::Body::FingerType::Pinky);

									Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
									FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
									DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

									Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
									FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
									DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

									Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
									FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
									DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

									EHand.Fingers.push_back(make_shared<Efficio::Body::Finger>(pinky));

									break;
								}
								//Put each EHand into EfficioFrame:
								EfficioFrame EFrame(f);
								}
							}

							//To do: add constructor to EfficioFinger that uses FingerType
								//added - finger types are already specified in enumerations as Finger.
								//we can rename Finger to FingerType, add Finger Types as derived classes of base class Finger, etc.

							//find bone to find joint position in leap library or other library
								//would this resolve overspecification?
									//strong probably
							//for Leap, Bone JointPosition gives bone
							//Note JointPosition does not return a Vector3. I think we need a Vector3 (or an equivalent, such as a multimap 
							//containing arrays of Vector3 equivalents)
							/*

					//will build generalizeable model for specific collection utilization
						//mod multimap first, based on class diagram UML
						//multimap is below as altnernative. can select among/between options to optimize for diversified utilities
						/*
						#include <unordered_multimap>

						unordered_multimap ARmap<int, unordered_multimap<string, unordered_multimap<string, <unordered_multimap<float, unordered_multimap<float, float>>>>>(); //constructor/declaration
						~unordered_multimap ARmap(); //deconstructor
						//ARmap(frame, hand, finger, joint x, joint y, joint z)

						*/
						}
					}
				}
			}
		}
		historicalFrames.AddFrame(efficioFrame);
		return efficioFrame;
	}

	std::shared_ptr<Efficio::EfficioFrame> Engine::GetFrame(int count)
	{
		auto tempFrame = historicalFrames.GetFrame(count);

		if (tempFrame)
		{
			return historicalFrames.GetFrame(count);
		}

		return NULL;
	}
}