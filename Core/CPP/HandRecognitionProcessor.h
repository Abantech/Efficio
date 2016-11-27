#pragma once

#include "RecognitionProcessor.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body 
		{
			/// Base class for all recognition that may occur within the Efficio system.
			extern class DLLEXPORT HandRecognitionProcessor : public RecognitionProcessor
			{
			public:

				// Inherited via RecognitionProcessor
				virtual std::vector<std::shared_ptr<Efficio::Events::Event>> DetectEvents(Efficio::Frame frame) override;
				virtual Efficio::Data::DataType GetDataType() override;
			};
		}
	}
}