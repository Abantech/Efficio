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
			// Forward delcaration to avoid circular references
			class Hand;

			/// Representation of the human finger
			extern class DLLEXPORT Finger
			{
			public:
				Finger(Efficio::Models::Body::FingerType fingerType, bool isExtended, float length, Joint tip, Joint dip, Joint mcp, Joint pip);
				~Finger();

				Joint Tip;
				Joint DIP;
				Joint MCP;
				Joint PIP;

				Hand* Hand;

				/// Which finger the object is representing
				const FingerType FingerType;

				const bool IsExtended;

				const float Length;
			};
		}
	}
};