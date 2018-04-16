#include "HandRecognitionProcessor.h"
#include "PinchEvent.h"
#include "PointEvent.h"
#include "FistEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			HandRecognitionProcessor::HandRecognitionProcessor() {}
			HandRecognitionProcessor::~HandRecognitionProcessor() {}

			std::string HandRecognitionProcessor::GetDataType()
			{
				return "Hand";
			}

			std::string HandRecognitionProcessor::GetName()
			{
				return "Efficio Hand Recognition Processor";
			}

			std::vector<std::shared_ptr<Event>> HandRecognitionProcessor::DetectEvents(std::shared_ptr<Data> data)
			{
				std::vector<std::shared_ptr<Event>> events;
				auto handData = dynamic_cast<Models::Body::HandData*>(data.get());
				
				auto pinchEvents = DetectPinch(*handData);
				for (size_t i = 0; i < pinchEvents.size(); i++)
				{
					events.push_back(std::move(pinchEvents[i]));                               
				}

				auto pointEvents = DetectPointing(*handData);
				for (size_t i = 0; i < pointEvents.size(); i++)
				{
					events.push_back(std::move(pointEvents[i]));
				}

				return events;
			}

			std::vector<std::shared_ptr<Event>> HandRecognitionProcessor::DetectPinch(Models::Body::HandData data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data.Hands.size(); i++)
				{
					auto hand = data.Hands[i];

					for (size_t j = 0; j < 4; j++)
					{
						auto finger1 = hand.Fingers[j];

						for (size_t k = j + 1; k < 5; k++)
						{
							auto distance = finger1.Tip.DistanceTo(hand.Fingers[k].Tip);
							if (distance < 15)
							{
								events.push_back(std::shared_ptr<Event>(new PinchEvent(GetName(), finger1, hand.Fingers[k], hand.Side)));
							}
						}
					}
				}

				return events;
			}

			std::vector<std::shared_ptr<Event>> HandRecognitionProcessor::DetectPointing(Models::Body::HandData data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data.Hands.size(); i++)
				{
					auto hand = data.Hands[i];

					if (hand.numberOfExtendedFingers == 1 && hand.extendedFingerIndicies[0] == 1)
					{
						events.push_back(std::shared_ptr<Event>(new PointEvent(GetName(), hand.Fingers[1], hand.Side)));
					}
				}

				return events;
			}

			std::vector<std::shared_ptr<Event>> HandRecognitionProcessor::DetectFist(Models::Body::HandData data)
			{
				std::vector<std::shared_ptr<Event>> events;

				for (size_t i = 0; i < data.Hands.size(); i++)
				{
					auto hand = data.Hands[i];

					if (hand.numberOfExtendedFingers == 0)
					{
						events.push_back(std::shared_ptr<Event>(new FistEvent(GetName(), hand.Side)));
					}
				}

				return events;
			}
		}
	}
}