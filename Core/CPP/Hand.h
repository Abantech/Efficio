#pragma once

#include "Vector3.h"
#include <array>
#include "Finger.h"
#include "Enumerations.h"
#include <vector>
#include <memory>


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
				Hand(Efficio::Body::BodySide side);
				Hand(std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> fingers, Efficio::Body::BodySide side);
				//Hand(std::array<Efficio::Models::Human::Finger, 5> fingers, Efficio::Body::BodySide side);
				~Hand();
				std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> GetFingers();
				void AddFinger(std::shared_ptr<Efficio::Models::Human::Finger> fingerPtr);
				Efficio::Body::BodySide Side;
				std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> Fingers;
				bool IsLeftHand;
			private:
				//std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> fingers;
				//std::vector<std::shared_ptr<Efficio::Events::Event>> events;
				//std::vector<std::shared_ptr<Efficio::Models::Human::Hand>> hands;
			};
		}
	}
}