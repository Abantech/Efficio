#pragma once
#include "Frame.h"
#include "Event.h"
#include <vector>
#include <memory>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#endif

namespace Efficio
{
	/// Object containing all processed and raw signals
	extern class DLLEXPORT EfficioFrame : public Frame
	{
	public:
		EfficioFrame(int ID);
		~EfficioFrame();
		std::vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();
		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);
		int ID;
	private:
		std::vector<std::shared_ptr<Efficio::Events::Event>> events;
	};
}