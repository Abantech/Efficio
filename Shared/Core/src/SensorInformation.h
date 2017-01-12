#pragma once

#include <string>


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
		class DLLEXPORT SensorInformation
		{
		public:
			SensorInformation();
			~SensorInformation();

			std::string Name;
		};
	}
}