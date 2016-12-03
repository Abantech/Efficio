//Step 1: Identify Output System Module variable naming conventions and structure
//Step 2: Customize mdimmmapgen structures and names for output system
//Step 3 If Greg and/or James are interested: Build Analytic Tools and graphing

#pragma once
//Note the multimaps approach might be fashioned to high-performance tracking and analytics, while the class approach might be best fashioned for functionality, such as advanced gaming

#include <unordered_map>
#include <string>
#include <array>
//#include <vector>

//#include "Engine.h" //utility?
//#include <iostream> //utility?
//#include "Enumerations.h"
#include "Vector3.h"
//#include "PinchDetector.h"
//#include  "Leap.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//note the pluses and minuses of the multidimensional multimap approach
//activities like pinching aren't as appropriate here at present, as compared to the class system. 
//The class system facilitates pinching. While classless pinching may appear feasible, note maps are classes unto themselves.
//Map pinching is possible, provided a tailored pinch class using map keys and containers rather than objects

using namespace std;

namespace Efficio {


	//fmap(frameID, handside, finger, joint x, joint y, joint z)

	//declaration
	unordered_multimap<int, unordered_multimap<string, unordered_multimap<string, unordered_multimap<float, unordered_multimap<float, float>>>>> VRmap;

	for (int index = 0; index < hands.count(); ++index)
	{

		Efficio::EfficioHand EHand = EfficioHand::EfficioHand();
		vector<shared_ptr<EfficioFinger>> handFingers = vector<shared_ptr<EfficioFinger>>();
		for (int f = 0; f < hands[i].fingers().count; f++)
		{

			//To populate: iterate through each part adding keys and container values in the engine

			//add frame number:
			//add hand side:
			if (EHand.isLeft())
			{
				//use Efficio library or, probably better, input device naming conventions, to determine handedness
				//value names will be customized to output software	

				//next step is matching values to input/output device conventions
				//value names depend on the depth and compatbility of the middleware
				//customized multimaps generator a possibility by device

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
				}

				if (Ehand.isRight())
					//add finger name, add joint positions
				{

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
					}

					//adjustments may include arrays and potentially vectors for portions of the multimap arrangement

					//Array Organization:
					//int fsf[10000][10000][10000]; //frame-side-finger
					//int jc[10000][10000][10000][10000]; //joint-coordinates

					//multidimensional vector design:
					//vector< vector<int> vector<string> vector<string> vector<string> vector<float> vector<float> vector<float> > vrvec;
					//use switch to iterate likewise

					//Example extension: design a user function to study hand movements, such as remote surgery or surgical training paths
					//e.g.,

					//Request user input of study parameters to isolate one or a group of nodes
					//startframe, endframe, hand side, finger
					//ofstream to output software

					//void graphPath(startframe, endframe, hand, finger, joint, z) { //all paramaters are optional. excluding parameters defaults to all in the 3d scape
					
						//void graphPathInWindow() {
							//Step 1: Identify Output Program and Its Specifications to Customize for
							//direct to display program OR generate own program
							//fstream to program read file OR create and print to window
							//transfer data to program storage
							//direct output program to graph data
							//x, y, z axis, allow user click-and-drag rotations and scroll-wheel zoom
							//display frameID and joint coordinates to user


						//};

						//void graphPathIn3dScape() {
							//Identify Output Program and Its Specifications to Customize for

							//direct to output device
							//transfer data to output device storage
							//direct output device to display to user
							//requires compatible data formatting for high-performance data transition
							//into specialized wrap or bypass wrap with alternative?
						//};
				}
			}
		}
	}
							}
						}
					}
				}