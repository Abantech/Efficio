#pragma once

#include <string>;

namespace Efficio
{
	class Data {
	public:
		Data() {};
		~Data() {};
		virtual std::string GetDataType() = 0;
	};
}