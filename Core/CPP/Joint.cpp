#include "Joint.h"
namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Joint::Joint(Vector3 position, JointType type) : Position(position), Type(type)
			{
			}
			Joint::~Joint()
			{
			}
		}
	}
}