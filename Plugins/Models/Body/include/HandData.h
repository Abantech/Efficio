#pragma once

#include "Data.h"
#include "Hand.h"
#include <vector>

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			class HandData : public Data
			{
			public:
				HandData();
				HandData(std::vector<Hand> hands);
				~HandData();

				std::vector<Hand> Hands;

				/// <summary>
				/// Gets the type of the data.
				/// </summary>
				/// <returns></returns>
				std::string GetDataType() { return "Hand"; }
			};
		}
	}
}