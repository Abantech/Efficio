#pragma once

#include "Joint.h"
#include "BoneTypes.h"
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
		namespace Body
		{
			/// A segment between two joints
			extern class DLLEXPORT Bone
			{
			public:
				Bone(Joint proximalJoint, Joint distalJoint);
				~Bone();

				const Joint ProximalJoint;
				const Joint DistalJoint;
				const BoneType Type;
				const float Length();
				const float Width();

				// TODO change to quaternion
				const int Rotation();

				// TODO figure out what this is. Leap uses it
				const int Basis();
				const Vector3 Center();
				const Vector3 Direction();

			};
		}
	}
}