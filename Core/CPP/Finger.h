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
	namespace Body
	{
		extern class DLLEXPORT Finger
		{
		public:
			Finger(Efficio::Body::FingerType FingerType);
			~Finger();
			vector<shared_ptr<FingerJoint>> FingerJoints;
		};
		//can we specify FingerTypes as derived classes enumerated in Enumerations.h (pinky, ring, middle, index, thumb)?
		//can we add derived classes of FingerTypes?
	}
};