#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include "vector.hpp"

namespace Efficio
{
	extern class DLLEXPORT Vector3
	{
	public:
		Vector3(float x, float y, float z);
		~Vector3();
		float X();
		float Y();
		float Z();

	private:
		vmml::Vector3f vector;
	};
}
