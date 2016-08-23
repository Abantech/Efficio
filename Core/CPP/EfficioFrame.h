#pragma once
#include "Frame.h"
#include "Event.h"
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
	extern class DLLEXPORT EfficioFrame : public Frame
	{
	public:
		EfficioFrame();
		~EfficioFrame();
		std::vector<std::shared_ptr<Efficio::Event>> GetEvents();
		void AddEvent(Efficio::Event* eventPtr);
	private:
		std::vector<std::shared_ptr<Efficio::Event>> events;
	};
}