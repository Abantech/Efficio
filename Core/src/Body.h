#pragma once

#include "Head.h"
#include "Arm.h"
#include "Leg.h"
#include "Joint.h"
#include "Bone.h"
#include "BoneTypes.h"
#include <array>
#include <vector>

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
			/// Representation of a human body
			extern class DLLEXPORT Body
			{
			public:
				Body();
				~Body();

				/// The head of the body
				Head Head;

				/// The arms of the body
				std::array<Arm, 2> Arms;

				/// The legs of the body
				std::array<Leg, 2> Legs;

				/// The shoulder joint
				Joint ShoulderCenter;

				/// The spine joint
				Joint Spine;

				/// The center hip joint
				Joint HipCenter;

				Bone Neck();

				Bone UpperSpine();

				Bone LowerSpine();

				/// Gets a joint by jointType
				Joint GetJoint(JointType jointType);

				/// Gets a collection of joints by joint type
				std::vector<Joint> GetJoints(std::vector<JointType> jointTypes);

				Bone GetBone( BoneType boneType);
			};
		}
	}
}
