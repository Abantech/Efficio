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
			Joint::Joint(Vector3 position, JointType type) : Joint(position, type, -1)
			{
			}
			Joint::Joint(Vector3 position, JointType type, float confidence) : Position(position), Type(type), Confidence(confidence), Valid(true)
			{
			}
			Joint::~Joint()
			{
			}

			std::vector<Joint> Joint::ProximalJoints(Joint joint)
			{
				return std::vector<Joint>();
			}

			std::vector<Joint> Joint::DistalJoints(Joint joint)
			{
				return std::vector<Joint>();
			}

			float Joint::DistanceTo(Joint joint)
			{
				return Position.DistanceTo(joint.Position);
			}
		}
	}
}