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
		EfficioFinger(Efficio::Body::FingerType FingerType);
		vector<shared_ptr<FingerJoint>> FingerJoints;
		~EfficioFinger();
		
	};
	//can we specify FingerTypes as derived classes enumerated in Enumerations.h (pinky, ring, middle, index, thumb)?
	//can we add derived classes of FingerTypes?

};