#pragma once

#include "DataType.h"
#include "Event.h"
#include "Frame.h"

#include <vector>
#include <memory>

#if _WINDLL
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		/// Base class for all recognition that may occur within the Efficio system.
		extern class DLLEXPORT RecognitionProcessor
		{
		public:
			RecognitionProcessor();
			~RecognitionProcessor();

			virtual std::vector<std::shared_ptr<Efficio::Events::Event>> DetectEvents(Efficio::Frame frame) = 0;

			virtual Efficio::Data::DataType GetDataType() = 0;
		};
	}
}