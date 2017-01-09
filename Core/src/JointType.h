#pragma once

#if _WINDLL
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
			/// Enumeration containing all of the joints of the body
			extern enum class DLLEXPORT JointType {
				None,
				Head,
				ShoulderCenter,
				ShoulderRight,
				ElbowRight,
				WristRight,
				HandRight,
				ShoulderLeft,
				ElbowLeft,
				WristLeft,
				HandLeft,
				Spine,
				HipCenter,
				HipRight,
				KneeRight,
				AnkleRight,
				FootRight,
				HipLeft,
				KneeLeft,
				AnkleLeft,
				FootLeft,
				RightHandThumbIP,
				RightHandThumbMCP,
				RightHandThumbCMP,
				RightHandThumbTIP,
				RightHandIndexMCP,
				RightHandIndexPIP,
				RightHandIndexDIP,
				RightHandIndexTIP,
				RightHandMiddleMCP,
				RightHandMiddlePIP,
				RightHandMiddleDIP,
				RightHandMiddleTIP,
				RightHandRingMCP,
				RightHandRingPIP,
				RightHandRingDIP,
				RightHandRingTIP,
				RightHandPinkyMCP,
				RightHandPinkyPIP,
				RightHandPinkyDIP,
				RightHandPinkyTIP,
				LeftHandThumbIP,
				LeftHandThumbMCP,
				LeftHandThumbCMP,
				LeftHandThumbTIP,
				LeftHandIndexMCP,
				LeftHandIndexPIP,
				LeftHandIndexDIP,
				LeftHandIndexTIP,
				LeftHandMiddleMCP,
				LeftHandMiddlePIP,
				LeftHandMiddleDIP,
				LeftHandMiddleTIP,
				LeftHandRingMCP,
				LeftHandRingPIP,
				LeftHandRingDIP,
				LeftHandRingTIP,
				LeftHandPinkyMCP,
				LeftHandPinkyPIP,
				LeftHandPinkyDIP,
				LeftHandPinkyTIP
			};
		}
	}
}