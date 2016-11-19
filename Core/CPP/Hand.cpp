#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Hand::Hand(BodySide side, std::array<Finger, 5> fingers) : Side(side), Fingers(fingers)
			{
			}
			Hand::~Hand()
			{
			}
		}
	}
}