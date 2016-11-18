#pragma once

#include "JointType.h"
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
			/// A body joint
			extern class DLLEXPORT Joint {
			public:
				Joint(Vector3 position, JointType type);
				~Joint();

				/// The joint's position
				const Vector3 Position;

				/// The joint's type
				const JointType Type;
			};
		}
	}
}