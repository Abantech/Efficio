#include "InputRecognitionEngine.h"
#include "HandRecognitionProcessor.h"

namespace Efficio
{
	namespace InputRecognition
	{
		InputRecognitionEngine::InputRecognitionEngine()
		{
			// TODO check if hand processing is happening
			//processors.push_back(std::shared_ptr<RecognitionProcessor>(new Body::Hands::HandRecognitionProcessor()));
		}

		InputRecognitionEngine::~InputRecognitionEngine()
		{
		}

		std::vector<std::shared_ptr<Efficio::Events::Event>> InputRecognitionEngine::ProcessFrame(std::shared_ptr<Efficio::Frame> frame)
		{
			auto events = std::vector<std::shared_ptr<Efficio::Events::Event>>();

			for (size_t i = 0; i < processors.size(); i++)
			{
				auto detectedEvents = processors[i]->DetectEvents(*frame);

				for (size_t j = 0; j < detectedEvents.size(); j++)
				{
					events.push_back(detectedEvents[j]);
				}
			}

			return events;
		}
	}
}