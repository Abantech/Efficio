#pragma once

#include "vector.hpp"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif



namespace Efficio
{
	extern class DLLEXPORT Vector3
	{
	public:
		Vector3(float x, float y, float z);
		~Vector3();
		float DistanceTo(Efficio::Vector3 vector2);
		float X();
		float Y();
		float Z();

	private:
		vmml::Vector3f vector;
	};
}
