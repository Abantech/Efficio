#include "Frame.h"
#include "HandJoint.h"
//#include "Leap.h"


Efficio::Frame::Frame() { //constructor
	//There seem to be several options depending on the mechanics and preferences of generating variables from sensor input data
	//Leap.h likely needed for input data specific to each HandJoint
	//option: iterate for P values from array or other input data structure

	//DIP lh2PIP(Position(position), P, shared_ptr, *P);
	DIP lh3PIP(*P);
	DIP lh4PIP(*P);
	DIP lh5PIP(*P);

	DIP rh2PIP(*P);
	DIP rh3PIP(*P);
	DIP rh4PIP(*P);
	DIP rh5PIP(*P);

	PIP lh2PIP(*P);
	PIP lh3PIP(*P);
	PIP lh4PIP(*P);
	PIP lh5PIP(*P);

	PIP rh2PIP(*P);
	PIP rh3PIP(*P);
	PIP rh4PIP(*P);
	PIP rh5PIP(*P);

	MCP lh1MCP(*P);
	MCP lh2MCP(*P);
	MCP lh3MCP(*P);
	MCP lh4MCP(*P);
	MCP lh5MCP(*P);

	MCP rh1MCP(*P);
	MCP rh2MCP(*P);
	MCP rh3MCP(*P);
	MCP rh4MCP(*P);
	MCP rh5MCP(*P);

	CMC lh1CMC(*P);
	CMC rh1CMC(*P);
}

Efficio::Frame::~Frame() { //destructor

}

/*sample main() below - might be pasted into MainPage.cpp
*ptr1
//P should be received from Vector3 for each (for_each, for loop, and/or while loop) HandJoint

//To call any member function: ptr1->memberfunction;
*/
