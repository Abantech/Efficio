#include "Hand.h"
#include <vector>
#include <memory>

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Hand::Hand()
			{
			}

			Hand::Hand(Efficio::Body::BodySide side) : Side(side)
			{
			}
			
			Hand::Hand(std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> fingers, Efficio::Body::BodySide side) : Fingers(fingers), Side(side)
			{
			}

			Hand::~Hand()
			{
			}

			std::vector<std::shared_ptr<Efficio::Models::Human::Finger>> Hand::GetFingers()
			{
				return Fingers;
			}

			void Hand::AddFinger(std::shared_ptr<Efficio::Models::Human::Finger> fingerPtr)
			{
				Fingers.push_back(std::shared_ptr<Efficio::Models::Human::Finger>(fingerPtr));
			}
		}
	}
}