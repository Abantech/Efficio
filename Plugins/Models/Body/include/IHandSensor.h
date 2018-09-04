#pragma once

#include "HandData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Any sensor which can feed hand data into Efficio
			class IHandSensor
			{
			public:
				IHandSensor() {};
				~IHandSensor() {};

				virtual void EnableHandTracking(bool enable) = 0;
			protected:
				virtual HandData GetHandData() = 0;
			};
		}
	}
}