#pragma once

#include "vector.hpp"

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
	class DLLEXPORT Vector3
	{
	public:
		Vector3();
		Vector3(float x, float y, float z);
		~Vector3();
		float DistanceTo(Vector3 vector2);
		float X();
		float Y();
		float Z();
		float Yaw();
		float Pitch();
		float Roll();
		static Vector3 Midpoint(Vector3 v1, Vector3 v2);
	private:
		vmml::Vector3f vector;
	};
}
