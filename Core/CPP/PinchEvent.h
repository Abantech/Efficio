#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include <string>
#include "vector.hpp"
#include "Enumerations.h"
#include "Event.h"
#include "Vector3.h"

namespace Efficio
{
	namespace Body
	{
		namespace Hands {
			/// The event raised when a pinch is detected from one of the devices tracking hands.
			extern class DLLEXPORT PinchEvent :  public Event
			{
			public:
				PinchEvent(BodySide side, Vector3 position);
				~PinchEvent();

				/// The side of the body on which the pinch occurred
				BodySide Side;
				
				/// The finger involved in the pinch.
				std::string Finger1;

				/// The other finger involved in the pinch.
				std::string Finger2;

				/// The location of the pinch
				Efficio::Vector3 Position;
			};
		}
	}
}