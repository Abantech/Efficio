#pragma once

#include "Data.h"
#include "Event.h"

#include <memory>
#include <vector>
#include <ctime>

namespace Efficio
{
	/// Container for all data and events that occurred within the context of the device queried
	class Frame
	{
	public:
		Frame(std::shared_ptr<Frame> previousFrame = NULL, int ID = 0);
		~Frame();

		std::vector<std::shared_ptr<Data>> GetData();
		void AddData(std::vector<std::shared_ptr<Data>> data);

		void AddFrame(Frame frame);

		std::vector<std::shared_ptr<Event>> GetEvents();
		void AddEvent(std::shared_ptr<Event> eventPtr);
		void AddEvents(std::vector<std::shared_ptr<Event>> eventsPtr);

		clock_t Time;

		clock_t DeltaTime;

		int ID;

	private:
		std::vector<std::shared_ptr<Data>> dataCollection;
		std::vector<std::shared_ptr<Event>> events;
	};
}