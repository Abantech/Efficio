#pragma once

#include "Body.h"
#include "Data.h"
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
			extern class DLLEXPORT SkeletalData : public Data::Data
			{
			public:
				SkeletalData();
				~SkeletalData();

				std::vector<Models::Body::Body> Bodies;
			};
		}
	}
}