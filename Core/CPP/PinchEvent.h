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
			extern class DLLEXPORT PinchEvent :  public Event
			{
			public:
				PinchEvent(BodySide side, Vector3 position);
				~PinchEvent();

				BodySide Side();
				std::string Finger1();
				std::string Finger2();
				Efficio::Vector3 Position();
			private:
				std::string finger1;
				std::string finger2;
				BodySide side;
				Efficio::Vector3 position;
			};
		}
	}
}