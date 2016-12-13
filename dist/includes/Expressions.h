#pragma once


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Data
	{
		namespace Body
		{
			namespace Face
			{
				extern enum class DLLEXPORT Expressions
				{
					LeftBrowRaised = 0,
					RightBrowRaised = 1,
					LeftBrowLowered = 2,
					RightBrowLowered = 3,

					Smiling = 4,
					Kissing = 5,
					OpenMouth = 6,

					LeftEyeClosed = 7,
					RightEyeClosed = 8,

					LeftEyeOpened = 9,
					RightEyeOpened = 10,
					EyesLookingLeft = 11,
					EyesLookingRight = 12,
					EyesLookingUp = 13,
					EyesLookingDown = 14,
					
					TongueOut = 15,
					LeftCheekPuffed = 16,
					RightCheekPuffed = 17
				};
			}
		}
	}
}