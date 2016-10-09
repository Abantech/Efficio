#pragma once
#include "Frame.h"
#include "Event.h"
#include "EfficioHand.h"
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
		std::vector<shared_ptr<Efficio::EfficioHand>> Hands;
		std::vector<shared_ptr<Efficio::Events::Event>> events;

	public:
		int ID;
		EfficioFrame(int ID);
		~EfficioFrame();
		std::vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();
		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);
	};
}