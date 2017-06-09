#include "InputRecognitionEngine.h"

namespace Efficio
{
	InputRecognitionEngine::InputRecognitionEngine()
	{
	}

	InputRecognitionEngine::~InputRecognitionEngine()
	{
	}

	std::vector<std::shared_ptr<Event>> InputRecognitionEngine::ProcessFrame(std::shared_ptr<Frame> frame)
	{
		auto events = std::vector<std::shared_ptr<Event>>();

		for (size_t i = 0; i < processors.size(); i++)
		{
			auto data = frame->GetDataOfType(processors[i]->GetDataType());

			for (size_t j = 0; j < data.size(); j++)
			{
				auto detectedEvents = processors[i]->DetectEvents(data[i]);

				for (size_t j = 0; j < detectedEvents.size(); j++)
				{
					events.push_back(detectedEvents[j]);
				}
			}
		}

		return events;
	}
}