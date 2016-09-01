#pragma once

#include "Vector3.h"
#include "Bone2.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			extern class DLLEXPORT Joint
			{
			public:
				Joint(std::string name, Vector3 position);
				~Joint();
				std::string Name;
				Vector3 Position;
				Efficio::Models::Human::Bone2 Bone;
			private:

			};
		}
	}
}