#pragma once
#include "Frame.h"
#include "Event.h"
#include "Hand.h"
#include <vector>
#include <memory>

using namespace Efficio;

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Object containing all processed and raw signals
	extern class DLLEXPORT EfficioFrame : public Frame
	{
		public:
			std::vector<std::shared_ptr<Efficio::Models::Body::Hand>> Hands;
		std::vector<std::shared_ptr<Efficio::Events::Event>> events;
		int ID;
		EfficioFrame(int ID);
		//what is the purpose of ID? Can the EfficioFrame constructor instead receive Hands?
		~EfficioFrame();
		std::vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();
		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);
	};
}