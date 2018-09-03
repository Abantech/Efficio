#include "HandRecognitionProcessor.h"
#include "PinchDetector.h"
#include "FistDetector.h"
#include "PointDetector.h"
#include "PinchEvent.h"
#include "PointEvent.h"
#include "FistEvent.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			HandRecognitionProcessor::HandRecognitionProcessor() 
			{
				this->Detectors.push_back(std::shared_ptr<IHandEventDetector>(new PinchDetector()));
				this->Detectors.push_back(std::shared_ptr<IHandEventDetector>(new FistDetector()));
				this->Detectors.push_back(std::shared_ptr<IHandEventDetector>(new PointDetector()));
			}
			
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

				for (size_t i = 0; i < this->Detectors.size(); i++)
				{
					auto events = this->Detectors[i]->DetectEvent(handData);

					for (size_t j = 0; j < events.size(); j++)
					{
						events.push_back(std::move(events[j]));
					}
				}

				return events;
			}
		}
	}
}