#pragma once
#include "EfficioFinger.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT EfficioHand
	{
	public:
		EfficioFinger Fingers [];
		
		EfficioHand();
		~EfficioHand();
	

	};
}