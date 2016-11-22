#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Hand::Hand(BodySide side, std::array<Finger, 5> fingers, float confidence) : Side(side), Fingers(fingers), Confidence(confidence)
			{
				for (size_t i = 0; i < Fingers.size(); i++)
				{
					Fingers[i].Hand = this;
				}
			}

			Hand::~Hand()
			{
			}
		}
	}
}