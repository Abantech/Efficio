#pragma once
#include "Joint.h"
#include "FingerType.h"

#if WINDOWS
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Representation of the human finger
			class DLLEXPORT Finger
			{
			public:
				Finger();
				Finger(FingerType fingerType, bool isExtended, float length, Joint tip, Joint dip, Joint mcp, Joint pip);
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