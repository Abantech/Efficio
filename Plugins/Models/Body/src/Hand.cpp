#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Hand::Hand() {}
			Hand::Hand(BodySide side, std::array<Finger, 5> fingers, float confidence) : Side(side), Fingers(fingers), Confidence(confidence) { }
			Hand::~Hand() { }

			std::vector<int> Hand::ExtendedFingerIndicies()
			{
				std::vector<int> extendedFingers;

				for (size_t i = 0; i < 5; i++)
				{
					if (this->Fingers[i].IsExtended)
					{
						extendedFingers.push_back(i);
					}
				}

				return extendedFingers;
			}

			int Hand::NumberOfExtendedFingers()
			{
				int extended = 0;

				for (size_t i = 0; i < 5; i++)
				{
					if (this->Fingers[i].IsExtended)
					{
						extended++;
					}
				}

				return extended;
			}
		}
	}
}