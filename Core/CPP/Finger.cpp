#include "Finger.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Finger::Finger()
			{
			}
			Finger::Finger(FingerName fingerName, std::map<Efficio::Models::Human::JointName, Efficio::Vector3> jointPositions) : Name(fingerName), jointPositions(jointPositions)
			{
			}
			Finger::~Finger()
			{
			}
			Efficio::Vector3 Finger::GetJointPosition(Efficio::Models::Human::JointName jointName)
			{
				return jointPositions.at(jointName);
			}
		}
	}
}