#include "Joint.h"

namespace Efficio
{
	namespace Models
	{
		namespace Human
		{
			Joint::Joint(std::string name, Vector3 position) : Name(name), Position(position)
			{
			}
			Joint::~Joint()
			{
			}
		}
	}
}