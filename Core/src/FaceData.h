#pragma once

#include "Data.h"
#include "Expressions.h"
#include <vector>
#include <map>

#if _WINDLL
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
			namespace Face
			{
				extern class DLLEXPORT FaceData : public Data
				{
				public:
					FaceData();
					~FaceData();

					std::map<Expressions, int> Expressions;

					/// <summary>
					/// Gets the type of the data.
					/// </summary>
					/// <returns></returns>
					DataType GetDataType() { return DataType::Face; }
				};
			}
		}
	}
}