#pragma once
#include "Frame.h"
#include "Event.h"
#include <vector>
#include <memory>
#include "Joint.h"

using namespace std;

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
			extern class DLLEXPORT Finger
			{
			public:
				Finger(FingerType fingerType);
				~Finger();
				vector<shared_ptr<Joint>> FingerJoints;
				const FingerType fingerType;
			};
			//can we specify FingerTypes as derived classes enumerated in Enumerations.h (pinky, ring, middle, index, thumb)?
			//can we add derived classes of FingerTypes?

			extern enum class DLLEXPORT FingerType {
				Thumb,
				Index,
				Middle,
				Ring,
				Pinky
			};
		}
	}
};