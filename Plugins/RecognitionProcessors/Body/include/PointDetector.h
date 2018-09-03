#pragma once

#include "IHandEventDetector.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class PointDetector : public IHandEventDetector
			{
			public:
				PointDetector();
				~PointDetector();

				std::vector<std::shared_ptr<Event>> DetectEvent(Models::Body::HandData* data) override;
			};
		}
	}
}