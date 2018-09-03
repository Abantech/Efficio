#pragma once

#include "IRecognitionProcessor.h"
#include "IHandEventDetector.h"
#include "HandData.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class HandRecognitionProcessor : public IRecognitionProcessor
			{
			public:
				HandRecognitionProcessor();
				~HandRecognitionProcessor();
				std::string GetDataType() override;
				std::string GetName() override;
				std::vector<std::shared_ptr<Event>> DetectEvents(std::shared_ptr<Data> data) override;
				std::vector<std::shared_ptr<IHandEventDetector>> Detectors;
			private:
				std::vector<std::shared_ptr<Event>> DetectPointing(Models::Body::HandData data);
				std::vector<std::shared_ptr<Event>> DetectFist(Models::Body::HandData data);
			};
		}
	}
}