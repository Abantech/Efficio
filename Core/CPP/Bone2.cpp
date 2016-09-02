#include "Bone2.h"
#include "Joint.h"
#include "Vector3.h"

	namespace Efficio
	{
		namespace Models
		{
			namespace Human
			{
				/// Default constructor for Bone Class
				Bone2::Bone2(std::string name) : Name(name) {}

				/// Initializes the Bone class with a single joint that represents both start and end joint (i.e zero lenght bone)
				Bone2::Bone2(std::string name, Joint* startJoint) : Name(name), StartJoint(startJoint), EndJoint(startJoint) { }

				/// Initializes the Bone class with a single joint that represents both joints
				Bone2::Bone2(std::string name, Joint* startJoint, Joint* endJoint) : Name(name), StartJoint(startJoint), EndJoint(endJoint) { }

				Efficio::Vector3 Bone2::GetStartPosition()
				{
					return StartJoint->Position;
				}

				Efficio::Vector3 Bone2::GetEndPosition()
				{
					return EndJoint->Position;
				}

				Efficio::Models::Human::Joint* Bone2::GetOppositeJoint(Efficio::Models::Human::Joint* joint)
				{
					return joint == StartJoint ? EndJoint : StartJoint;
				}

				Bone2::~Bone2()
				{
				}

			}
		}
	}