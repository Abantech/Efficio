#pragma once
#include "Joint.h"
#include "FingerType.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Representation of the human finger
			class Finger
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