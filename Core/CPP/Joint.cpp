#include "Joint.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Joint::Joint(Efficio::Models::Human::JointName name, Vector3 position) : Name(name), Position(position)
			{
			}
			Joint::~Joint()
			{
			}
		}
	}
}