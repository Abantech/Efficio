#pragma once
#include "Vector3.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//every time the Efficio frame gets created, make the hand joint positions updated
//call
//use Position(position)
//use shared_ptr
//



namespace Efficio 
{
	extern class DLLEXPORT HandJoint
	{
	public:
		HandJoint(Vector3 position);
		Vector3 Position;
			//P is position
		~HandJoint();
	};
}
