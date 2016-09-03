#include "EfficioFrame.h"


namespace Efficio
{
	EfficioFrame::EfficioFrame(int ID) : ID(ID)
	{
	}

	EfficioFrame::~EfficioFrame()
	{
		
	}
	std::vector<std::shared_ptr<Efficio::Events::Event>> EfficioFrame::GetEvents()
	{
		return events;
	}

	std::vector<std::shared_ptr<Efficio::Models::Human::Hand>> EfficioFrame::GetHands()
	{
		return std::vector<std::shared_ptr<Efficio::Models::Human::Hand>>();
	}

	void EfficioFrame::AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr)
	{
		events.push_back(std::shared_ptr<Efficio::Events::Event>(eventPtr));
	}

	void EfficioFrame::AddHand(std::shared_ptr<Efficio::Models::Human::Hand> handPtr)
	{
		hands.push_back(std::shared_ptr<Efficio::Models::Human::Hand>(handPtr));
	}
}