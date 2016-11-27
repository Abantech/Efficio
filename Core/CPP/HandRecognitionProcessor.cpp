#include "HandRecognitionProcessor.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			std::vector<std::shared_ptr<Efficio::Events::Event>> HandRecognitionProcessor::DetectEvents(Efficio::Frame frame)
			{
				std::vector<std::shared_ptr<Efficio::Events::Event>> events;

				// TODO detect events

				return events;
			}

			Efficio::Data::DataType HandRecognitionProcessor::GetDataType()
			{
				return Efficio::Data::DataType::Hand;
			}
		}
	}
}