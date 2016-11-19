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
				Finger(Efficio::Models::Body::FingerType fingerType, Joint tip, Joint dip, Joint mcp, Joint pip);
				~Finger();

				const Joint Tip;
				const Joint DIP;
				const Joint MCP;
				const Joint PIP;

				/// Which finger the object is representing
				const FingerType FingerType;
			};
		}
	}
};