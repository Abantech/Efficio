//Step 1: Identify Output System Module variable naming conventions and structure
//Step 2: Customize mdimmmapgen structures and names for output system
//Step 3 if Greg is interested: Build Analytic Tools
//Step 4: Hopefully James, Greg, and/or I will write an upstream conversion layer 
//for abstracting-joint-data that will efficiently or with customization efficiently function for mdimmmapgen

#include <unordered_map>
//#include <string>
//#include <array>
//#include <vector>

#include "Engine.h" //utility?
#include <iostream> //utility?
//#include "Enumerations.h"
#include "Vector3.h"
//#include "PinchDetector.h"
#include  "Leap.h"


//studying the data input mechanism. Should we receive all data per frame, then iterate for meaning, or generate meaning point-by-point?

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
							//where have handside requests been taking place? It might not be relevant in the engine, but developers, surgeons, and gamers may find it favorable
							Efficio::EfficioHand EHand = EfficioHand::EfficioHand();
							vector<shared_ptr<EfficioFinger>> handFingers = vector<shared_ptr<EfficioFinger>>();
							for (int f = 0; f < hands[i].fingers().count; f++)
							{
				
				//To populate: iterate through each part adding keys and container values in the engine

				//determine to what extent key combinations are required to access container values rather than one key per container

				//add frame number:
				//add hand side:
				if (EHand.isLeft()) //use Efficio library or, probably better, input device naming conventions, to determine handedness
						//value names will be customized to output software	

					//adjustments can include arrays, and potentially vectors, sets, and lists, for portions of the multimap arrangement

					//next step is matching values to input/output device conventions
					//value names depend on the depth and compatbility of the middleware
						//use customized generator for each input/output system?
						//build converter layer on adjacent to the middleware on both sides?

					//multidimensional array exmaple with ints as "keys" in the "legend"
					//left = 0; pinky = 0, etc. right = 1. dip = 0, pip = 1, mcp = 2. 
					//int frame [1000][1000][1000];
					//float vec[1000][1000][1000];

					//and/or no Vector3 maps, depending on UX module

					//multidimensional vector design:
					//vector< vector<int> vector<string> vector<string> vector<string> vector<float> vector<float> vector<float> > vrvec;
					//use switch to iterate likewise

					//list does not make sense because new elements are just added to the end
					//sets probably won't work, because they're not associative


				switch (hands[i].fingers()[f].type) {
				case Leap::Finger::TYPE_PINKY:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					
					break;

				case Leap::Finger::TYPE_RING:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

						break;

				case Leap::Finger::TYPE_MIDDLE:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

						break;

				case Leap::Finger::TYPE_INDEX:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);


						break;

				case Leap::Finger::TYPE_THUMB:
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
					VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

						break;

						if (Ehand.isRight())
							//add finger name, add joint positions

						switch (hands[i].fingers()[f].type) {
						case Leap::Finger::TYPE_PINKY:
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							break;

						case Leap::Finger::TYPE_RING:
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

								break;

						case Leap::Finger::TYPE_MIDDLE:
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

								break;

						case Leap::Finger::TYPE_INDEX:
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"pip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

								break;

						case Leap::Finger::TYPE_THUMB:
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"dip", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);
							VRMap.insert(frameID, unordered_multimap<"left", unordered_multimap<"pinky", unordered_multimap<"mcp", unordered_multimap<Vector3.x(), unordered_multimap<Vector3.y(), Vector3.z()>>>>>);

								break;


								//Array Organization:
								array VRMultidimarray[10000][10000][10000][10000][10000][10000][10000] = new array;


							//Next, we can design a user function to study hand movements, such as remote surgery or surgical training paths
							//e.g.,

								//Request user input of study parameters to isolate one or a group of nodes
									//startframe, endframe, hand side, finger
								//ofstream to output software

							void graphPath(startframe, endframe, hand, finger, joint, z) { //all paramaters are optional. excluding parameters defaults to all in the 3d scape
							
					
							void graphPathInWindow() {
								//Step 1: Identify Output Program and Its Specifications to Customize for
								//direct to display program OR generate own program
									//fstream to program read file OR create and print to window
								//transfer data to program storage
								//direct output program to graph data
									//x, y, z axis, allow user click-and-drag rotations and scroll-wheel zoom
									//display frameID and joint coordinates to user

							
							};

							void graphPathIn3dScape() {
								//Step 1: Identify Output Program and Its Specifications to Customize for

								//direct to output device
								//transfer data to output device storage
								//direct output device to display to user
									//requires compatible data formatting for high-performance data transition
										//into specialized wrap or bypass wrap with alternative?
							};
							
							/*
							Earlier outlook: 
							
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