#pragma once

#include "SingleHandGesture.h"
#include "DiscreteGesture.h"
#include "Vector3.h"
#include "Hand.h"
#include "BodySide.h"

#if _WINDLL
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio 
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				extern class DLLEXPORT Pinch : public DiscreteGesture
				{
				public:
					Pinch(Efficio::Models::Body::BodySide side, Efficio::Models::Body::Finger finger1, Efficio::Models::Body::Finger finger2);
					~Pinch();
					Vector3 Position;
					Efficio::Models::Body::Finger Finger1;
					Efficio::Models::Body::Finger Finger2;
					Efficio::Events::EventType GetEventType();
					Efficio::Models::Body::BodySide Side;
				};
			}
		}
	}
}