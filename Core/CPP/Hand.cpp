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

			Hand::Hand(std::vector<Efficio::Models::Human::Finger> fingers, Efficio::Body::BodySide side) : Fingers(fingers), Side(side)
			{
			}

			Hand::~Hand()
			{
			}
		}
	}
}