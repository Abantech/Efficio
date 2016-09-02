#pragma once

#include "Joint.h"
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
			extern enum class DLLEXPORT FingerJointName
			{
				Distal,
				Intermediate,
				Proximal,
				Metacarpal
			};

			extern class DLLEXPORT FingerJoint : public Efficio::Models::Human::Joint
			{
			public: FingerJoint(std::string name, Vector3 position);
					~FingerJoint();
					std::string Name;
					//FingerJoint Position;
			};
		}
	}
}