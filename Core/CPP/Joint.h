#pragma once

#include "JointType.h"
#include "Vector3.h"
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
			/// A body joint
			extern class DLLEXPORT Joint 
			{
			public:
				/// Constructor for when confidence values are not available. Sets the confidence property to -1.
				Joint(Vector3 position, JointType type);
				Joint(Vector3 position, JointType type, float confidence);
				~Joint();

				/// The joint's position
				const Vector3 Position;

				/// The joint's type
				const JointType Type;

				/// The confidence of the joint. A valie of -1 indicates that no confidence data was provided
				const float Confidence;

				/// Gets the proximal joints of a joint, treating spine as origin. If joint is spine, spine is returned;
				const std::vector<Joint> ProximalJoints(Joint joint);

				/// Gets the distal joints of a joint, treating spine as origin. If joint is most distal, joint is returned;
				const std::vector<Joint> DistalJoints(Joint joint);

				/// The distance between two joints
				const float DistanceTo(Joint joint);
			};
		}
	}
}