#pragma once

#include "Vector3.h"
#include "Enumerations.h"
#include "EfficioFinger.h"
#include "FingerJoint.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//R: every time the Efficio frame gets created, make the hand joint positions updated
//S: view constructor in Frame.cpp
//R: call
//R: use Position(position)
//R: use shared_ptr

//S: Top-down organization:
//lh, rh
//lh1, lh2, lh3, lh4, lh5; rh1, rh2, rh3, rh4, rh5
//joints of the hand: fingers 2 through 5 (nonthumbs)
//Distal interphalangeal: DIP
//Proximal interphilangeal: PIP
//Metacarpophalangeal: MCP
//joints of the hand: finger 1 (thumb)
//Interphalangeal: IP
//Metacarpophalangeal: MCP
//Carpometaparpal: CMC


namespace Efficio
{
	FingerJoint::FingerJoint(Efficio::Body::FingerJointType jointName) : Position(0, 0, 0)

	{
		JointName = jointName;


	}
}

//make a default constructor!?