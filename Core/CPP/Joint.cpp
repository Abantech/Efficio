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

			std::string Joint::GetJointNameString()
			{
				switch (Name)
				{
					case JointName::Distal: return "Distal";
					case JointName::Intermediate: return "Intermediate";
					case JointName::Proximal: return "Proximal";
					case JointName::Metacarpal: return "Metacarpal";
					default:      return "Unknown or non existent Joint Type";
				}
			}
		}
	}
}