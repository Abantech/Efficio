#pragma once

#include "EfficioHand.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT SkeletalData
	{
	public:
		SkeletalData();
		~SkeletalData();

		//Hands vector of shared_pointers
		vector<shared_ptr <EfficioHand>> HumanHand;
		//BVHData GetBVHData()
		//BVHData bvhData

	};
}