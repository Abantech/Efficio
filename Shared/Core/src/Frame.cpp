#include "Frame.h"
//#include "Leap.h"
#include <vector>
#include "Vector3.h"

namespace Efficio
{
	Frame::Frame(std::shared_ptr<Frame> previousFrame, int id) : ID(id), dataCollection()
	{
		Time = clock();

		if (previousFrame)
		{
			DeltaTime = ((Time - previousFrame->Time) / ((float)CLOCKS_PER_SEC)) * 1000;
		}
	}

	Frame::~Frame() {

	}

	std::vector<std::shared_ptr<Data::Data>> Frame::GetData()
	{
		return dataCollection;
	}

	void Frame::AddData(std::vector<std::shared_ptr<Data::Data>> data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			dataCollection.push_back(std::shared_ptr<Data::Data>(data[i]));
		}
	}

	void Frame::AddFrame(Frame frame)
	{
		AddData(frame.GetData());	
		AddEvents(frame.GetEvents());
	}

	std::vector<std::shared_ptr<Events::Event>> Frame::GetEvents()
	{
		return events;
	}

	void Frame::AddEvent(std::shared_ptr<Events::Event> eventPtr)
	{
		events.push_back(std::shared_ptr<Events::Event>(eventPtr));
	}

	void Frame::AddEvents(std::vector<std::shared_ptr<Events::Event>> eventsPtr)
	{
		for (size_t i = 0; i < eventsPtr.size(); i++)
		{
			AddEvent(eventsPtr.at(i));
		}
	}
}