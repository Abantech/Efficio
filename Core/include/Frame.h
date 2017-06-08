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
		/// @param previousFrame The frame before the current frame
		/// @param ID The ID of the frame
		Frame(std::shared_ptr<Frame> previousFrame = NULL, int ID = 0);
		~Frame();

		/// Gets the data from the frame
		std::vector<std::shared_ptr<Data>> GetData();

		/// Adds data to the frame 
		void AddData(std::vector<std::shared_ptr<Data>> data);

		/// Merges frames
		void AddFrame(Frame frame);

		/// Gets the events from the frame
		std::vector<std::shared_ptr<Event>> GetEvents();

		/// Adds an event to the frame
		void AddEvent(std::shared_ptr<Event> eventPtr);

		/// Adds events to the frame
		void AddEvents(std::vector<std::shared_ptr<Event>> eventsPtr);

		/// The time the frame was collected
		clock_t Time;

		/// The time since the previous frame was collected
		clock_t DeltaTime;

		/// The unique identifier of the frame
		int ID;

	private:
		std::vector<std::shared_ptr<Data>> dataCollection;
		std::vector<std::shared_ptr<Event>> events;
	};
}