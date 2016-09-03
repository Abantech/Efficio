#pragma once

#include "Vector3.h"

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
			extern enum class DLLEXPORT JointName
			{
				Distal,
				Intermediate,
				Proximal,
				Metacarpal
			};

			extern class DLLEXPORT Joint
			{
			public:
				Joint(Efficio::Models::Human::JointName name, Vector3 position);
				~Joint();
				std::string GetJointNameString();
				JointName Name;
				Vector3 Position;
			private:

			};
		}
	}
}