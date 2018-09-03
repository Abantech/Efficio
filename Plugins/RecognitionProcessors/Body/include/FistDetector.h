#pragma once

#include "IHandEventDetector.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class FistDetector : public IHandEventDetector
			{
			public:
				FistDetector();
				~FistDetector();

				std::vector<std::shared_ptr<Event>> DetectEvent(Models::Body::HandData* data) override;
			};
		}
	}
}