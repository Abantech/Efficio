#include "Finger.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Finger::Finger(Efficio::Models::Body::FingerType fingerType, array<shared_ptr<Joint>, 4> joints) : FingerType(fingerType), Joints(joints)
			{
			}
			Finger::~Finger()
			{
			}
		}
	}
}