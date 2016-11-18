#pragma once
#include "Enumerations.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio {
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				extern class DLLEXPORT SingleHandGesture
				{
				public:
					SingleHandGesture(Body::BodySide side);
					~SingleHandGesture();
					Body::BodySide Side;
				};
			}
		}
	}
}