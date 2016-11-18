#pragma once

#include "Hand.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT HandData
	{
	public:
		HandData();
		~HandData();
		std::vector<Efficio::Models::Human::Hand> Hands;
	};
}
