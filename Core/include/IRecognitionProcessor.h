#pragma once

#include "Event.h"
#include "Frame.h"

#include <vector>
#include <memory>

namespace Efficio
{
	/// Base class for all recognition that may occur within the Efficio system.
	class IRecognitionProcessor
	{
	public:
		IRecognitionProcessor();
		~IRecognitionProcessor();

		virtual std::vector<std::shared_ptr<Event>> DetectEvents(Efficio::Frame frame) = 0;

		virtual std::string GetDataType() = 0;
	};
}