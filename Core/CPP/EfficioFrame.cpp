#include "EfficioFrame.h"

namespace Efficio
{
	EfficioFrame::EfficioFrame()
	{
	}

	EfficioFrame::~EfficioFrame()
	{
	}
	std::vector<std::shared_ptr<Event>> EfficioFrame::GetEvents()
	{
		return events;
	}
	void EfficioFrame::AddEvent(Efficio::Event * eventPtr)
	{
		events.push_back(std::shared_ptr<Efficio::Event>(eventPtr));
	}
}