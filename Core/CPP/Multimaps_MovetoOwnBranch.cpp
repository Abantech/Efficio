#include <unordered_map>
#include <string>

#include "Engine.h"
#include <iostream> //utility?
#include "Enumerations.h"
#include "Vector3.h"
#include "PinchDetector.h"
#include  "Leap.h"


//studying how the data is inputted. Should we take in all data per frame, then iterate for meaning, or give it meaning point-by-point?

//note the pluses and minuses of the multidimensional multimap approach
	//activities like pinching aren't as appropriate here at present, as compared to the class system. 
	//The class system facilitates pinching. While classless pinching may appear feasible, note maps are classes unto themselves.
	//Map pinching is possible, provided a tailored pinch class.

using namespace std;

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

	//fmap(frameID, handside, finger, joint x, joint y, joint z)

	//the idea here is to eliminate a lot of classes for higher performance while retaining sensible naming conventions that make sense for developers, populating movements
	//into a sensible map for user performance optimization, with applications ranging from surgery to gaming

	//declaration
	unordered_multimap<int, unordered_multimap<string, unordered_multimap<string, unordered_multimap<float, unordered_multimap<float, float>>>>> VRmap;

	
	shared_ptr<Efficio::EfficioFrame> Engine::GetFrame()
	{
		shared_ptr<Efficio::EfficioFrame> efficioFrame(new EfficioFrame(frameID++));
		
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
							//where have we been requesting whether it's left or right hand? It might not be relevant in the engine, but developers, surgeons, and gamers may find it favorable
							Efficio::EfficioHand EHand = EfficioHand::EfficioHand();
							vector<shared_ptr<EfficioFinger>> handFingers = vector<shared_ptr<EfficioFinger>>();
							for (int f = 0; f < hands[i].fingers().count; f++)
							{
				
				//To populate: iterate through each part adding keys and container values in the engine

				//add frame number:
				//add hand side:
				if (hand.isLeft())
										
				switch (hands[i].fingers()[f].type) {
				case Leap::Finger::TYPE_PINKY:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;
					
					break;

				case Leap::Finger::TYPE_RING:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"ring", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"ring", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"ring", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

						break;

				case Leap::Finger::TYPE_MIDDLE:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"middle", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"middle", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"middle", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

						break;

				case Leap::Finger::TYPE_INDEX:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"index", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"index", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"index", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MIP).z() >>>>>;


						break;

				case Leap::Finger::TYPE_THUMB:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"thumb", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"thumb", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCPP).z() >>>>>;

						break;

						if (hand.isRight())
							//add finger name, add joint positions

						switch (hands[i].fingers()[f].type) {
						case Leap::Finger::TYPE_PINKY:
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;
							break;

						case Leap::Finger::TYPE_RING:
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"ring", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"ring", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"ring", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

								break;

						case Leap::Finger::TYPE_MIDDLE:
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"middle", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"middle", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"middle", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

								break;

						case Leap::Finger::TYPE_INDEX:
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"index", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z())>>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"index", unordered_multimap<"pip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_PIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"index", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

								break;

						case Leap::Finger::TYPE_THUMB:
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"thumb", unordered_multimap<"dip", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_DIP).z() >>>>>;
							VRMap.insert(frameID, unordered_multimap<"right", unordered_multimap<"thumb", unordered_multimap<"mcp", unordered_multimap<Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).x(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).y(), Vector3(hands[i].fingers()[f].jointPosition(Leap::Finger::JOINT_MCP).z() >>>>>;

								break;

							//Next, we can design a user function to study hand movements, such as remote surgery or surgical training paths
							//e.g.,
							
							void graphPath(startframe, endframe, hand, finger, joint, z) {
							
							void graphPathInWindow() {
								//direct to display program OR generate own program
								//transfer data to program storage
								//direct output program to graph data
							};

							void graphPathIn3dScape() {
								//direct to output device
								//transfer data to output device storage
								//direct ouput device to display to user
							};
							
							/*
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