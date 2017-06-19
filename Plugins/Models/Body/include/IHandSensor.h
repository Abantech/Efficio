#pragma once

#include "HandData.h"
#include "Sensor.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Any sensor which can feed data into Efficio
			class IHandSensor : public Efficio::Sensor
			{
			public:
				IHandSensor() {};
				~IHandSensor() {};

				virtual void EnableHandTracking(bool enable) = 0;
			protected:
				virtual Efficio::Models::Body::HandData GetHandData() = 0;
			};
		}
	}
}