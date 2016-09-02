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
				Bone2(std::string name, Efficio::Models::Human::Joint* startJoint);
				Bone2(std::string name, Efficio::Models::Human::Joint* startJoint, Efficio::Models::Human::Joint* endJoint);
				~Bone2();
				std::string Name;
				Efficio::Vector3 GetStartPosition();
				Efficio::Vector3 GetEndPosition();
				bool IsInitialized;
				Efficio::Models::Human::Joint *StartJoint;
				Efficio::Models::Human::Joint *EndJoint;
				Efficio::Models::Human::Joint* GetOppositeJoint(Efficio::Models::Human::Joint *joint);
			private:
			};
		}
	}
};

