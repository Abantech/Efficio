#pragma once

#include "IRecognitionProcessor.h"
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
			private:
				std::vector<std::shared_ptr<Event>> DetectPinch(Models::Body::HandData data);
				std::vector<std::shared_ptr<Event>> DetectPointing(Models::Body::HandData data);
				std::vector<std::shared_ptr<Event>> DetectFist(Models::Body::HandData data);
			};
		}
	}
}