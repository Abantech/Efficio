#pragma once

#include "Event.h"
#include "HandData.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class IHandEventDetector
			{
			public:
				IHandEventDetector() {};
				~IHandEventDetector() {};

				virtual std::vector<std::shared_ptr<Event>> DetectEvent(Models::Body::HandData* data) = 0;
			};
		}
	}
}