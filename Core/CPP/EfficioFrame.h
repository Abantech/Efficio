#pragma once
#include "Frame.h"
#include "Event.h"
#include "Hand.h"
#include <vector>
#include <memory>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Object containing all processed and raw signals
	extern class DLLEXPORT EfficioFrame
	{
	public:
		EfficioFrame(int ID);
		~EfficioFrame();
		std::vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();
		std::vector<std::shared_ptr<Efficio::Models::Human::Hand>> GetHands();
		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);
		void AddHand(std::shared_ptr<Efficio::Models::Human::Hand> handPtr);
		int ID;
	private:
		std::vector<std::shared_ptr<Efficio::Events::Event>> events;
		std::vector<std::shared_ptr<Efficio::Models::Human::Hand>> hands;
	};
}