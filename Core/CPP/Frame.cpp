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

	std::map<Data::DataType, std::vector<std::shared_ptr<Data::Data>>> Frame::GetData()
	{
		return dataCollection;
	}

	std::vector<std::shared_ptr<Data::Data>> Frame::GetDataOfType(Data::DataType dataType)
	{
		std::vector<std::shared_ptr<Data::Data>> data;

		if (dataCollection.count(dataType) > 0)
		{
			data = dataCollection.at(dataType);
		}

		return data;
	}

	void Frame::AddData(std::vector<std::shared_ptr<Data::Data>> data)
	{
		if (data.size() < 1)
		{
			return;
		}

		for (size_t i = 0; i < data.size(); i++)
		{
			auto type = data[i]->GetDataType();

			if (!dataCollection.count(type))
			{
				std::vector<std::shared_ptr<Data::Data>> vec;
				dataCollection.emplace(type, vec);
			}

			dataCollection.at(type).push_back(data[i]);
		}
	}

	void Frame::AddFrame(Frame frame)
	{
		auto data = frame.GetData();

		for (std::map<Data::DataType, std::vector<std::shared_ptr<Data::Data>>>::iterator it = data.begin(); it != data.end(); ++it)
		{
			AddData(it->second);
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