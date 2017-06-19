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
			class HandData : public Efficio::Data
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
				std::string GetDataType() { return "Hand"; }
			};
		}
	}
}