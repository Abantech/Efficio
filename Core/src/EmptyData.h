#pragma once

#include "Data.h"

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
		extern class DLLEXPORT EmptyData : public Data
		{
		public:
			EmptyData() {};
			~EmptyData() {};
			virtual DataType GetDataType() override;
		};
	}
}