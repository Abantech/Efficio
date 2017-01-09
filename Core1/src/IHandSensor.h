#pragma once

#include "HandData.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		/// Any sensor which can feed data into Efficio
		extern class DLLEXPORT IHandSensor
		{
		public:
			IHandSensor() {};
			~IHandSensor() {};

			virtual void EnableHandTracking(bool enable) = 0;
		protected:
			virtual Data::Body::HandData GetHandData() = 0;
		};
	}
}