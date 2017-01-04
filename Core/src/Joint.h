#pragma once

#include "JointType.h"
#include "Vector3.h"
#include <vector>

#if WIN
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
	namespace Models
	{
		namespace Body
		{
			/// A body joint
			extern class DLLEXPORT Joint 
			{
			public:
				Joint();
				/// Constructor for when confidence values are not available. Sets the confidence property to -1.
				Joint(Vector3 position, JointType type);
				Joint(Vector3 position, JointType type, float confidence);
				~Joint();

				bool Valid;

				/// The joint's position
				Vector3 Position;

				/// The joint's type
				JointType Type;

				/// The confidence of the joint. A valie of -1 indicates that no confidence data was provided
				float Confidence;

				/// Gets the proximal joints of a joint, treating spine as origin. If joint is spine, spine is returned;
				std::vector<Joint> ProximalJoints(Joint joint);

				/// Gets the distal joints of a joint, treating spine as origin. If joint is most distal, joint is returned;
				std::vector<Joint> DistalJoints(Joint joint);

				/// The distance between two joints
				float DistanceTo(Joint joint);
			};
		}
	}
}