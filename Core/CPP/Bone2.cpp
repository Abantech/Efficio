#include "Bone2.h"
#include "Joint.h"

	namespace Efficio
	{
		namespace Models
		{
			namespace Human
			{
				//Not really sure what I'm donig here but it seems to want a constructor definition for the vector
				Bone2::Bone2(std::string name) : Name(name)
				{
					//StartJoint.~Joint();
					//EndJoint.~Joint();
				}

				//Not really sure what I'm donig here but it seems to want a constructor definition for the vector
				Bone2::Bone2(std::string name, Joint StartJoint) : Name(name) //, StartJoint(startJoint), StartPosition(StartJoint.Position), EndPosition(Vector3(0, 0, 0)), EndJoint(Joint("joint2", EndPosition)), IsInitialized(true)
				{
					/*EndJoint.~Joint();*/
				}

				//Not really sure what I'm donig here but it seems to want a constructor definition for the vector
				Bone2::Bone2(std::string name, Joint StartJoint, Joint EndJoint) : Name(name) //, StartJoint(startJoint), EndJoint(endJoint), StartPosition(StartJoint.Position), EndPosition(EndJoint.Position), IsInitialized(true)
				{
				}

				//Not really sure what I'm donig here but it seems to want a constructor definition for the vector
				Bone2::Bone2(std::string name, Joint StartJoint, Vector3 EndPosition) : Name(name) //, StartJoint(startJoint), StartPosition(StartJoint.Position), EndPosition(endPosition), EndJoint(Joint("joint2", EndPosition)), IsInitialized(true)
				{
					/*EndJoint.~Joint();*/
				}

				Bone2::~Bone2()
				{
				}
			}
		}
	}