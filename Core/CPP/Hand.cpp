#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Hand::Hand()
			{
			}

			Hand::Hand(std::array<Efficio::Models::Human::Finger, 5> fingers, Efficio::Body::BodySide side) : Fingers(fingers), Side(side)
			{
			}

			std::vector<Efficio::Models::Human::Finger> Hand::GetFingers()
			{
				std::vector<Efficio::Models::Human::Finger> handFingers(std::begin(Fingers), std::end(Fingers));
				return handFingers;
			}

			Hand::~Hand()
			{
			}
		}
	}
}