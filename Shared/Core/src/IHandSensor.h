#pragma once

#include "HandData.h"

#if WINDOWS
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
	namespace Sensors
	{
		/// Any sensor which can feed data into Efficio
		class DLLEXPORT IHandSensor
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