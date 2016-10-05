#pragma once
#include "DatumType.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		extern class DLLEXPORT Datum {
		public:
			Datum() {};
			~Datum() {};
			virtual Efficio::Data::DatumType GetDatumType() = 0;
		};
	}
}