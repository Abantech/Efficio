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
		namespace Body
		{
			/// A body joint
			extern class DLLEXPORT Joint {
			public:
				Joint(Vector3 position, JointType type);
				~Joint();
				const Vector3 Position;
				const JointType Type;
			};

			/// Enumeration containing all of the joints of the body
			extern enum class DLLEXPORT JointType {
				RightHandThumbInterphalangeal,
				RightHandThumbMetacarpophalangeal,
				RightHandThumbCarpometaparpal,
				RightHandIndexMCP,
				RightHandIndexPIP,
				RightHandIndexDIP,
				RightHandMiddleMCP,
				RightHandMiddlePIP,
				RightHandMiddleDIP,
				RightHandRingMCP,
				RightHandRingPIP,
				RightHandRingDIP,
				RightHandPinkyMCP,
				RightHandPinkyPIP,
				RightHandPinkyDIP,
				LeftHandThumbInterphalangeal,
				LeftHandThumbMetacarpophalangeal,
				LeftHandThumbCarpometaparpal,
				LeftHandIndexMCP,
				LeftHandIndexPIP,
				LeftHandIndexDIP,
				LeftHandMiddleMCP,
				LeftHandMiddlePIP,
				LeftHandMiddleDIP,
				LeftHandRingMCP,
				LeftHandRingPIP,
				LeftHandRingDIP,
				LeftHandPinkyMCP,
				LeftHandPinkyPIP,
				LeftHandPinkyDIP,
			};
		}
	}
}