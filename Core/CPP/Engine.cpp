#include "Engine.h"
#include <iostream>
#include "Enumerations.h"
#include "Vector3.h"
#include "PinchDetector.h"
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
							Efficio::EfficioHand EHand = EfficioHand::EfficioHand();
							vector<shared_ptr<EfficioFinger>> handFingers = vector<shared_ptr<EfficioFinger>>();
							for (int f = 0; f < hands[i].fingers().count; f++)
							{
								switch (hands[i].fingers()[f].type) {
								case Leap::Finger::TYPE_THUMB:
								
									//EfficioFinger thumb = EfficioFinger(Efficio::Body::FingerType::Thumb);

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

									EHand.HandFingers.push_back(thumb);

									break;
								
						case Leap::Finger::TYPE_INDEX:
					
							EfficioFinger index = EfficioFinger(Efficio::Body::FingerType::Index);
												
						Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
						FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
						DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

						Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
						FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
						DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

						Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
						FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
						DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

						EHand.HandFingers.push_back(index);

						break;
					
						case Leap::Finger::TYPE_MIDDLE:
					
						EfficioFinger middle = EfficioFinger(Efficio::Body::FingerType::Middle);
											
						Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
						FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
						DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

						Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
						FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
						DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

						Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
						FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
						DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);
								
						EHand.HandFingers.push_back(middle);

						break;
					
						case Leap::Finger::TYPE_RING:
					
						EfficioFinger ring = EfficioFinger(Efficio::Body::FingerType::Ring);
								
						Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
						FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
						DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

						Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
						FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
						DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

						Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
						FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
						DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

						EHand.HandFingers.push_back(ring);

						break;
					
						case Leap::Finger::TYPE_PINKY:
					
						EfficioFinger pinky = EfficioFinger(Efficio::Body::FingerType::Pinky);

						Leap::Vector LeapDIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP);
						FingerJoint DIPJoint = FingerJoint(Efficio::Body::FingerJointType::DIP);
						DIPJoint.Position = Vector3(LeapDIPPositionVector.x, LeapDIPPositionVector.y, LeapDIPPositionVector.z);

						Leap::Vector LeapPIPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP);
						FingerJoint PIPJoint = FingerJoint(Efficio::Body::FingerJointType::PIP);
						DIPJoint.Position = Vector3(LeapPIPPositionVector.x, LeapPIPPositionVector.y, LeapPIPPositionVector.z);

						Leap::Vector LeapMCPPositionVector = hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP);
						FingerJoint MCPJoint = FingerJoint(Efficio::Body::FingerJointType::MCP);
						DIPJoint.Position = Vector3(LeapMCPPositionVector.x, LeapMCPPositionVector.y, LeapMCPPositionVector.z);

						EHand.HandFingers.push_back(pinky);

						break;
					
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
							To populate: iterate through each part adding keys and container values in the engine
							for frame
							add frame number
							for hand
							add "left" or "right"
							for finger
							add finger name
							for joint x, add point value
							for joint y, add point value
							for joint z, add add point value

							Then we can design a user function to study hand movements, such as remote surgery or surgical training paths
							e.g.,
							void chartpath(startframe, endframe, hand, finger, joint, z)
							{
							intakeData
							{
							}
							chartPath
							{
							}
							}

							We might also be able to do this without all the classes, as a performance alternative
							for utilities in which hand movements are simply tracked, by subtracting special funcitons like
							pinching from non-entertainment endeavors

							Basically, just Vector3, the wrap, and the Engine, or even without Vector3 as a class
		
							*/

							Efficio::InputRecognition::Human::Hands::PinchDetector detector;
							detector.Enabled = true;
							auto pinches = detector.Detect(hands[i]);

							for (size_t j = 0; j < pinches.size(); j++)
							{
								efficioFrame->AddEvent(pinches[j]);
							}
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