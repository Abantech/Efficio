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

			Hand::~Hand()
			{
			}
		}
	}
}