#include "Joint.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Joint::Joint() : Valid(false), Type(JointType::None), Confidence(-1)
			{
			}
			Joint::Joint(Efficio::Vector3 position, JointType type, float confidence) : Position(position), Type(type), Confidence(confidence), Valid(true)
			{
			}
			Joint::~Joint()
			{
			}

			float Joint::DistanceTo(Joint joint)
			{
				return Position.DistanceTo(joint.Position);
			}
		}
	}
}