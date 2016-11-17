#pragma once
#include "Finger.h"
#include "HandJoint.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Body
	{
		extern class DLLEXPORT Hand
		{

		public:
			Hand();
			~Hand();

			//vector<shared_ptr<EfficioHand>> Hands;
			vector<shared_ptr<HandJoint>> Joints;
			vector<shared_ptr<Finger>> Fingers;
			//HandType GetHandType();

			//Vector3 WristPosition;
		};
	}
}