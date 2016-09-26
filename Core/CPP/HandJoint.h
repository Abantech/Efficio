#pragma once
#include "Vector3.h"
#include "Enumerations.h"

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
	extern class DLLEXPORT HandJoint
	{
	public:
		HandJoint(Vector3 position);
		Vector3 Position;
			//P is position
		~HandJoint();
	};
	extern class DLLEXPORT DIP : public HandJoint
	{
	public:
		DIP(Vector3 position);
		Vector3 Position;
		~DIP();
	};
	extern class DLLEXPORT PIP : public HandJoint
	{
	public:
		PIP(Vector3 position);
		Vector3 Position;
		~PIP();
	};
	extern class DLLEXPORT MCP : public HandJoint
	{
	public:
		MCP(Vector3 position);
		Vector3 Position;
		~MCP();
	};
	extern class DLLEXPORT IP : public HandJoint
	{
	public:
		IP(Vector3 position);
		Vector3 Position;
		~IP();
	};
	extern class DLLEXPORT CMC : public HandJoint
	{
	public:
		CMC(Vector3 position);
		Vector3 Position;
		~CMC();
	};
	}
