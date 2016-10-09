#pragma once
#include "Frame.h"
#include "Event.h"
#include <vector>
#include <memory>
#include "FingerJoint.h"

using namespace std;

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT EfficioFinger
	{
	public:
		EfficioFinger();
		~EfficioFinger();

		vector<shared_ptr<FingerJoint>> FingerJoints;
	};
};