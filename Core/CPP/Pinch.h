#pragma once

#include "SingleHandGesture.h"
#include "DiscreteGesture.h"
#include "Vector3.h"
#include "Enumerations.h"
#include "Finger.h"

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
					Pinch(Body::BodySide side, Efficio::Models::Human::FingerName finger1, Efficio::Models::Human::FingerName finger2, Vector3 position);
					~Pinch();
					Vector3 Position;
					Efficio::Models::Human::FingerName Finger1;
					Efficio::Models::Human::FingerName Finger2;
					Efficio::Events::EventType GetEventType();
					Body::BodySide Side;
				};
			}
		}
	}
}