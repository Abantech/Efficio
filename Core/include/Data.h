#pragma once

#include <string>;

namespace Efficio
{
	/// The base class for all data that flows through Efficio
	class Data {
	public:
		Data() {};
		~Data() {};
		virtual std::string GetDataType() = 0;
	};
}