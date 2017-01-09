#pragma once

#include "Data.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
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