#pragma once

#include "Vector3.h"
#include <array>
#include <memory>
#include "Finger.h"
#include "Enumerations.h"


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif


namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			extern class DLLEXPORT Hand
			{
			public:
				Hand();
				Hand(std::array<Efficio::Models::Human::Finger, 5> fingers, Efficio::Body::BodySide side);
				~Hand();
				std::array<Efficio::Models::Human::Finger, 5> Fingers;
				Efficio::Body::BodySide Side;
				//void AddFinger(std::shared_ptr<Efficio::Models::Human::Finger> fingerPtr);
				std::vector<Efficio::Models::Human::Finger> GetFingers();
			private:
			};
		}
	}
}