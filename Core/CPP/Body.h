#pragma once

#include "Head.h"
#include "Arm.h"
#include "Leg.h"
#include "Joint.h"
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
				const Head Head;

				/// The arms of the body
				const std::array<Arm, 2> Arms;

				/// The legs of the body
				const std::array<Leg, 2> Legs;

				/// The shoulder joint
				const Joint ShoulderCenter;

				/// The spine joint
				const Joint Spine;

				/// The center hip joint
				const Joint HipCenter;

				/// Gets a joint by jointType
				const Joint GetJoint(JointType jointType);

				/// Gets a collection of joints by joint type
				const std::vector<Joint> GetJoints(std::vector<JointType> jointTypes);
			};
		}
	}
}
