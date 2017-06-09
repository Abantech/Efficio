#include "Frame.h"
#include <vector>

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

	std::vector<std::shared_ptr<Data>> Frame::GetData()
	{
		return dataCollection;
	}

	std::vector<std::shared_ptr<Data>> Frame::GetDataOfType(std::string type)
	{
		// TODO keep map of types and indicies for fast return
		std::vector<std::shared_ptr<Data>> data;

		for (size_t i = 0; i < dataCollection.size(); i++)
		{
			if (dataCollection[i]->GetDataType() == type)
			{
				data.push_back(dataCollection[i]);
			}
		}

		return data;
	}

	void Frame::AddData(std::vector<std::shared_ptr<Data>> data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			dataCollection.push_back(std::move(data[i]));
		}
	}

	void Frame::AddFrame(Frame frame)
	{
		AddData(frame.GetData());
		AddEvents(frame.GetEvents());
	}

	std::vector<std::shared_ptr<Event>> Frame::GetEvents()
	{
		return events;
	}

	void Frame::AddEvent(std::shared_ptr<Event> eventPtr)
	{
		events.push_back(std::move(eventPtr));
	}

	void Frame::AddEvents(std::vector<std::shared_ptr<Event>> eventsPtr)
	{
		for (size_t i = 0; i < eventsPtr.size(); i++)
		{
			AddEvent(eventsPtr.at(i));
		}
	}
}