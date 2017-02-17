#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Body {

		//define the below enumerations to James' wrappers
		extern enum class DLLEXPORT BodySide
		{
			Right,
			Left
		};

		extern enum class DLLEXPORT BodyTrackingType
		{
			Eye,
			Face,
			Hand,
			Arm,
			Body
		};

		extern enum class HandType
		{
			LeftHand,
			RightHand
		};
		extern enum class DLLEXPORT FingerType {
			Thumb,
			Index,
			Middle,
			Ring,
			Pinky
		};

		extern enum class DLLEXPORT FingerJointType {
			DIP,
			PIP,
			MCP
		};

	}

	extern enum DLLEXPORT GestureType {
		Discrete,
		Continuous
	};

	extern enum DLLEXPORT GestureState {
		InProgress,
		Completed
	};
}