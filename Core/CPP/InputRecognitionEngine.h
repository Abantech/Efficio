#pragma once

#include "Event.h"
#include "Frame.h"
#include "RecognitionProcessor.h"

#include <vector>
#include <memory>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		extern class DLLEXPORT InputRecognitionEngine {
		public:
			InputRecognitionEngine();
			~InputRecognitionEngine();

			std::vector<std::shared_ptr<Efficio::Events::Event>> ProcessFrame(std::shared_ptr<Efficio::Frame> frame);
		private:
			std::vector<std::shared_ptr<Efficio::InputRecognition::RecognitionProcessor>> processors;
		};
	}
}