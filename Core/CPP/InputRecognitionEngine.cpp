#include "InputRecognitionEngine.h"

namespace Efficio
{
	namespace InputRecognition
	{
		InputRecognitionEngine::InputRecognitionEngine()
		{
		}

		InputRecognitionEngine::~InputRecognitionEngine()
		{
		}

		std::vector<std::shared_ptr<Efficio::Events::Event>> InputRecognitionEngine::ProcessFrame(std::shared_ptr<Efficio::Frame> frame)
		{
			return std::vector<std::shared_ptr<Efficio::Events::Event>>();
		}
	}
}