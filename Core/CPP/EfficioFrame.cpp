#include "EfficioFrame.h"


namespace Efficio
{
	EfficioFrame::EfficioFrame(int ID) : ID(ID), Hands()
	{
	}

	EfficioFrame::~EfficioFrame()
	{
		
	}

	std::vector<std::shared_ptr<Efficio::Events::Event>> EfficioFrame::GetEvents()
	{
		return events;
	}

	void EfficioFrame::AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr)
	{
		events.push_back(std::shared_ptr<Efficio::Events::Event>(eventPtr));
	}
}