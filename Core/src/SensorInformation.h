#pragma once

#include <string>


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors
	{
		extern class DLLEXPORT SensorInformation
		{
		public:
			SensorInformation();
			~SensorInformation();

			std::string Name;
		};
	}
}