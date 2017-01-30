#pragma once

#include "SingleHandGesture.h"
#include "DiscreteGesture.h"
#include "Hand.h"
#include "BodySide.h"

#if WINDOWS
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
				class DLLEXPORT HandSupine : public DiscreteGesture
				{
				public:
					HandSupine(std::string source, Models::Body::BodySide side, int handID);
					~HandSupine();
					Events::EventType GetEventType();
					Models::Body::BodySide Side;
					int HandID;
				};
			}
		}
	}
}