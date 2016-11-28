#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Hand::Hand(BodySide side, std::array<Finger, 5> fingers, float confidence) : Side(side), Fingers(fingers), Confidence(confidence)
			{
			}

			Hand::~Hand()
			{
			}
		}
	}
}