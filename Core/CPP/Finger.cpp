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
			Finger::Finger(FingerName fingerName, std::map<std::string, Efficio::Vector3> jointPositions) : Name(fingerName), jointPositions(jointPositions)
			{
			}
			Finger::~Finger()
			{
			}
			Efficio::Vector3 Finger::GetJointPosition(std::string jointName)
			{
				return jointPositions.at(jointName);
			}
		}
	}
}