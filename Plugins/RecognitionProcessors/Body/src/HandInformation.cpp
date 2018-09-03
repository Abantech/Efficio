#include "HandInformation.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			HandInformation::HandInformation(std::string source, Models::Body::Hand hand)
				: DiscreteEvent(source), hand(hand) { }

			HandInformation::~HandInformation() {}

			std::string HandInformation::GetEventType()
			{
				return HandInformation::EventType;
			}

			const std::string HandInformation::EventType = "HandInformation";
		}
	}
}