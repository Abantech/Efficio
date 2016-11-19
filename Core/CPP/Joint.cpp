#include "Joint.h"
namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Joint::Joint(Vector3 position, JointType type) : Joint(position, type, -1)
			{
			}
			Joint::Joint(Vector3 position, JointType type, float confidence) : Position(position), Type(type), Confidence(confidence)
			{
			}
			Joint::~Joint()
			{
			}
		}
	}
}