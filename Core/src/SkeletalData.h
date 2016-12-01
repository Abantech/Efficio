#pragma once

#include "Hand.h"
#include <vector>
#include <memory>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		namespace Body
		{
			extern class DLLEXPORT SkeletalData
			{
			public:
				SkeletalData();
				~SkeletalData();

				//Hands vector of shared_pointers
				std::vector<std::shared_ptr <Models::Body::Hand>> HumanHand;
				//BVHData GetBVHData()
				//BVHData bvhData

			};
		}
	}
}