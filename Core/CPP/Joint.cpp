#include "Joint.h"
#include "Bone2.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Joint::Joint(std::string name, Vector3 position) : Name(name), Position(position)
			{
				if (!Bone.IsInitialized)//HOW TO NULL CHECK!?
				{
					Bone = Bone2(name, *this);
				}
				else
				{
					Bone.EndJoint = *this;
				}
			}
			Joint::~Joint()
			{
			}
		}
	}
}