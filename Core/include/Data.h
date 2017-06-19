#pragma once

#include <string>

namespace Efficio
{
	/// The base class for all data that flows through Efficio
	class Data {
	public:
		Data() {};
		~Data() {};

		/// The type of the data
		virtual std::string GetDataType() = 0;
	};
}