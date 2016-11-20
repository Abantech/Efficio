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
		/*
		lambda expression concept line for GetBVHData function
		(will be a function of BVH needs and parameters)
		BVHData GetBVHData(param1, param2)
		{
		auto lambdaBVH = [](param1, param2) {return param1 + param2};
		}
		*/
		//BVHData bvhData

	};
}