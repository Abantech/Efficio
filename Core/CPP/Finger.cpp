#include "Finger.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Finger::Finger(Efficio::Models::Body::FingerType fingerType, Joint tip, Joint dip, Joint mcp, Joint pip) : FingerType(fingerType), Tip(tip), DIP(dip), MCP(mcp), PIP(pip)
			{
			}
			Finger::~Finger()
			{
			}
		}
	}
}