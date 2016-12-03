#include "Frame.h"
//#include "Leap.h"
#include <vector>
#include "Vector3.h"

namespace Efficio
{
	Frame::Frame(int id) : ID(id), dataCollection()
	{
	}

	Frame::~Frame() {

	}

	std::vector<std::shared_ptr<Data::Data>> Frame::GetData()
	{
		return dataCollection;
	}

	void Frame::AddData(std::vector<std::shared_ptr<Data::Data>> data)
	{
		if (data.size() < 1)
		{
			return;
		}

		for (size_t i = 0; i < data.size(); i++)
		{
			dataCollection.push_back(data[i]);
		}
	}

	void Frame::AddFrame(Frame frame)
	{
		AddData(frame.GetData());	
		auto events = frame.GetEvents();

		for (size_t i = 0; i < events.size(); i++)
		{
			AddEvent(events[i]);
		}
	}

	std::vector<std::shared_ptr<Events::Event>> Frame::GetEvents()
	{
		return events;
	}

	void Frame::AddEvent(std::shared_ptr<Events::Event> eventPtr)
	{
		events.push_back(std::shared_ptr<Events::Event>(eventPtr));
	}
}