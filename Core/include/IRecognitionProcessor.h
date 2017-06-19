#pragma once

#include "Event.h"
#include "Data.h"

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

		/// Detects events within the data
		virtual std::vector<std::shared_ptr<Event>> DetectEvents(std::shared_ptr<Data> data) = 0;

		/// Gets the data type for which the processor works
		virtual std::string GetDataType() = 0;

		virtual std::string GetName() = 0;
	};
}