#pragma once

#include "SingleHandGesture.h"
#include "DiscreteGesture.h"
#include "Vector3.h"
#include "Enumerations.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio 
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				extern class DLLEXPORT Pinch : public DiscreteGesture
				{
				public:
					Pinch(Body::BodySide side, Body::Finger finger1, Body::Finger finger2, Vector3 position);
					~Pinch();
					Vector3 Position;
					Body::Finger(index);
					Body::Finger Finger2;
					Efficio::Events::EventType GetEventType();
					Body::BodySide Side;
				};
				//this seems more like a Body class than a Pinch class.
				//considering moving contents to Body, and writing new Pinch contents
				//will search to see whether we have an existing Pinch structure to adapt into C++ for Efficio functionality


				//how to build a pinch class for multimap nodes
				//Step 1:
				//declare members of Body class AND
				//access mdimmmapgen values
				//as a function of branch
				//Step 2:
				//identify Vector3 joint combination parameters required to be defined as a a pinch
				//write pinch function and pinch effects
				//Step 3:
				//ensure proper pinch engine/generator access
			}
		}
	}
}