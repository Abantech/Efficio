#pragma once
#include "Joint.h"
#include "FingerType.h"

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
				Finger();
				Finger(Efficio::Models::Body::FingerType fingerType, bool isExtended, float length, Joint tip, Joint dip, Joint mcp, Joint pip);
				~Finger();

				Joint Tip;
				Joint DIP;
				Joint MCP;
				Joint PIP;

				bool Valid;

				/// Which finger the object is representing
				FingerType FingerType;

				bool IsExtended;

				float Length;
			};
		}
	}
};