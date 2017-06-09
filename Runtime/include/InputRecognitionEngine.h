#pragma once

#include "Event.h"
#include "Frame.h"
#include "IRecognitionProcessor.h"

#include <vector>
#include <memory>

namespace Efficio
{
	/// The engine that is responsible for recognizing events from various inputs
	class InputRecognitionEngine
	{
	public:
		InputRecognitionEngine();
		~InputRecognitionEngine();

		/// Processes the frame
		std::vector<std::shared_ptr<Event>> ProcessFrame(std::shared_ptr<Frame> frame);
	private:
		std::vector<std::shared_ptr<IRecognitionProcessor>> processors;
	};
}