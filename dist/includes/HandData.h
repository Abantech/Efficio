#pragma once

#include "Data.h"
#include "Hand.h"
#include <vector>

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
			extern class DLLEXPORT HandData : public Data
			{
			public:
				HandData();
				HandData(std::vector<Models::Body::Hand> hands);
				~HandData();

				std::vector<Models::Body::Hand> Hands;

				/// <summary>
				/// Gets the type of the data.
				/// </summary>
				/// <returns></returns>
				DataType GetDataType() { return DataType::Hand; }
			};
		}
	}
}