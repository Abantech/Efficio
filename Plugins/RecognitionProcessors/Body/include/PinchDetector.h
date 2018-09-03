#pragma once

#include "IHandEventDetector.h"

namespace Efficio
{
	namespace Recognition
	{
		namespace Body
		{
			class PinchDetector : public IHandEventDetector
			{
			public:
				PinchDetector();
				~PinchDetector();

				std::vector<std::shared_ptr<Event>> DetectEvent(Models::Body::HandData* data) override;
			};
		}
	}
}