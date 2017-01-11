#pragma once
#include "DataType.h"

#if _WINDLL
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
	namespace Data
	{
		class DLLEXPORT Data {
		public:
			Data() {};
			~Data() {};
			virtual DataType GetDataType() = 0;
		};
	}
}