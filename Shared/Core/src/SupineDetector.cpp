#include "SupineDetector.h"
#include "HandSupine.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				SupineDetector::SupineDetector()
				{
				}
				SupineDetector::~SupineDetector()
				{
				}
				std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> SupineDetector::Detect(Models::Body::Hand hand)
				{
					std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>> gestures;

					if (hand.IsSupine())
					{
						gestures.push_back(std::shared_ptr<Gesture>(new HandSupine("EfficioSupineDetector", hand.Side)));
					}

					return gestures;
				}
			}
		}
	}
}