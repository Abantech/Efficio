#pragma once
#include "DataType.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		extern class DLLEXPORT Data {
		public:
			Data() {};
			~Data() {};
			virtual Efficio::Data::DataType GetDataType() = 0;
		};
	}
}