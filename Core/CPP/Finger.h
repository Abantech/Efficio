#pragma once
#include "Frame.h"
#include "Event.h"
#include <array>
#include <memory>
#include "Joint.h"
#include "FingerType.h"

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
			/// Representation of the human finger
			extern class DLLEXPORT Finger
			{
			public:
				Finger(Efficio::Models::Body::FingerType fingerType, array<shared_ptr<Joint>, 4> joints);
				~Finger();

				/// The joints of the finger
				const array<shared_ptr<Joint>, 4> Joints;

				/// Which finger
				const FingerType FingerType;
			};
		}
	}
};