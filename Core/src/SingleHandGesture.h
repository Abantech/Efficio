#pragma once

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
				extern class DLLEXPORT SingleHandGesture
				{
				public:
					SingleHandGesture(Efficio::Models::Body::BodySide side);
					~SingleHandGesture();
					Efficio::Models::Body::BodySide Side;
				};
			}
		}
	}
}