#pragma once

#include "RecognitionProcessor.h"
#include "SingleHandGestureDetector.h"

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
		namespace Body
		{
			namespace Hands
			{
				/// Base class for all recognition that may occur within the Efficio system.
				class DLLEXPORT HandRecognitionProcessor : public RecognitionProcessor
				{
				public:
					HandRecognitionProcessor();
					~HandRecognitionProcessor();

					// Inherited via RecognitionProcessor
					virtual std::vector<std::shared_ptr<Events::Event>> DetectEvents(Frame frame) override;
					virtual Efficio::Data::DataType GetDataType() override;

				private:
					std::vector<std::shared_ptr<Hands::SingleHandGestureDetector>> singleHandDetectors;
				};
			}
		}
	}
}