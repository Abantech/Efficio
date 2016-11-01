#pragma once
#include "HandJoint.h"
#include "Vector3.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif


namespace Efficio
{

	HandJoint::HandJoint(Vector3 position):Position(position)
	{
	}


	HandJoint::~HandJoint()
	{
	}
	IPCMC::~IPCMC()
	{
	}
	CMC::~CMC()
	{
	}
}
