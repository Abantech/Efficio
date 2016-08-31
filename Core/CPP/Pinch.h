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
				extern class DLLEXPORT Pinch : public SingleHandGesture, public DiscreteGesture
				{
				public:
					Pinch(Body::BodySide side, Body::Finger finger1, Body::Finger finger2, Vector3 position);
					~Pinch();
					Vector3 Position;
					Body::Finger Finger1;
					Body::Finger Finger2;
					Efficio::Events::EventType GetEventType();
				};
			}
		}
	}
}