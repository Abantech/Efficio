#pragma once

#include "Body.h"
#include "Data.h"
#include <vector>
#include <memory>

#if WINDOWS
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
		namespace Body
		{
			class DLLEXPORT SkeletalData : public Data
			{
			public:
				SkeletalData();
				~SkeletalData();

				std::vector<Models::Body::Body> Bodies;
			};
		}
	}
}