#include "Hand.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Hand::Hand(BodySide side, array<shared_ptr<Finger>, 5> fingers, vector<shared_ptr<Joint>> joints) : Side(side), Fingers(fingers), Joints(joints)
			{
			}

			Hand::~Hand()
			{
			}
		}
	}
}