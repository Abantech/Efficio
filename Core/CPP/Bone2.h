#pragma once

#include "Vector3.h"
#include "Joint.h"

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
			extern class DLLEXPORT Bone2
			{
			public:
				Bone2(std::string name);
				Bone2(std::string name, Efficio::Models::Human::Joint StartJoint);
				Bone2(std::string name, Efficio::Models::Human::Joint StartJoint, Efficio::Models::Human::Joint EndJoint);
				Bone2(std::string name, Efficio::Models::Human::Joint StartJoint, Vector3 endPosition);
				~Bone2();
				std::string Name;
				//Vector3 StartPosition;
				//Vector3 EndPosition;
				////bool IsInitialized;
				//Efficio::Models::Human::Joint StartJoint;
				//Efficio::Models::Human::Joint EndJoint;
			private:

			};
		}
	}
};

