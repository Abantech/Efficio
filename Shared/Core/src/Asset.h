#pragma once

#include "Sensor.h"
#include <vector>
#include <memory>
#include <string>

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
	class DLLEXPORT Asset {
	public:
		Asset(std::string name);
		~Asset();
		std::vector<std::shared_ptr<Efficio::Sensors::Sensor>> Sensors;
		std::string GetName();
	protected:
		
	private:
		std::string name;
	};
}