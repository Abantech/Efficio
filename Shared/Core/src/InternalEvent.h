#pragma once

#include "EventType.h"
#include "Event.h"

#if WINDOWS
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
	class DLLEXPORT InternalEvent : public Events::Event
	{
	public:
		InternalEvent();
		~InternalEvent();

		virtual Efficio::Events::EventType GetEventType() = 0;
	private:
	};
}