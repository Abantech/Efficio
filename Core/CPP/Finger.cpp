#include "Finger.h"
#include "Joint.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Finger::Finger()
			{
			}
			//Finger::Finger(FingerName fingerName, std::map<Efficio::Models::Human::JointName, Efficio::Vector3> jointPositions) : Name(fingerName), jointPositions(jointPositions)
			//{
			//}
			Finger::Finger(FingerName fingerName, std::vector<std::shared_ptr<Efficio::Models::Human::Joint>> joints) : Name(fingerName), Joints(joints)
			{
			}
			Finger::~Finger()
			{
			}

			Efficio::Vector3 Finger::GetJointPosition(Efficio::Models::Human::JointName jointName)
			{
				for (int i = 0; i <= Joints.size(); i++)
				{
					Efficio::Models::Human::Joint currentJoint = *(Joints.at(i));

					if (currentJoint.Name == jointName)
					{
						return currentJoint.Position;
					}
				}

				std::string error;
				error = "EFFICIO: No such joint name ('" + GetJointNameString(jointName) + "') found in finger " + GetFingerNameString();
				throw std::invalid_argument(error);
			}

			std::string Finger::GetFingerNameString()
			{
				switch (Name)
				{
					case FingerName::Thumb	: return "Thumb";
					case FingerName::Index	: return "Index";
					case FingerName::Middle	: return "Middle";
					case FingerName::Ring	: return "Ring";
					case FingerName::Pinky	: return "Pinky";
					default:      return "Unknown Finger Type";
				}
			}

			std::string Finger::GetJointNameString(Efficio::Models::Human::JointName jointName)
			{
				switch (jointName)
				{
				case Efficio::Models::Human::JointName::Distal: return "Distal";
				case Efficio::Models::Human::JointName::Intermediate: return "Intermediate";
				case Efficio::Models::Human::JointName::Proximal: return "Proximal";
				case Efficio::Models::Human::JointName::Metacarpal: return "Metacarpal";
				default:      return "Unknown or non existent Joint Type";
				}
			}
		}
	}
}