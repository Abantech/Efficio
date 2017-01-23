#pragma once

#include "Data.h"
#include "Event.h"

#include <memory>
#include <vector>
#include <map>
#include <ctime>

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
	class DLLEXPORT Frame
	{
	public:
		Frame(std::shared_ptr<Frame> previousFrame = NULL, int ID = 0);
		~Frame();

		std::vector<std::shared_ptr<Data::Data>> GetData();
		void AddData(std::vector<std::shared_ptr<Data::Data>> data);

		void AddFrame(Frame frame);

		std::vector<std::shared_ptr<Events::Event>> GetEvents();
		void AddEvent(std::shared_ptr<Events::Event> eventPtr);
		void AddEvents(std::vector<std::shared_ptr<Events::Event>> eventsPtr);

		clock_t Time;

		clock_t DeltaTime;

		int ID;

	private:
		std::vector<std::shared_ptr<Data::Data>> dataCollection;
		std::vector<std::shared_ptr<Events::Event>> events;
	};
}