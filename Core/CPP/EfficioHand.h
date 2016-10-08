#pragma once
#include "EfficioFinger.h"
#include "HandJoint.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT EfficioHand
	{

	public:
		EfficioHand();
		~EfficioHand();

	private:
		//vector<shared_ptr<EfficioHand>> Hands;
		vector<shared_ptr<HandJoint>> Joints;
		vector<shared_ptr<EfficioFinger>> HandFingers;
		//HandType GetHandType();

		//Vector3 WristPosition;
	};
}