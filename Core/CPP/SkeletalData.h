//ensure that only one skeletaldata.h is included
#pragma once

//include statements
#include <string>
//#include <array>

//in this "header" file or in other portion of generic, ensure proper devices are selected, with the correct wrapper included
//#include [wrapper selection] 
//#include <Vector3.h>
//#include <iostream> to print to console for testing, display



#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

using namespace std;

//namespace efficio

//namespace body

//skeletal data

//joints as nodes

//must be generic

//will receive input data thru wrapper or directly from input system

//joint groups

//base class joint(string side, float x-coordinate, float y-coordinate, float z-coordinate, optional float/string health, optional float/string density, optional float/string size)
{
string side = side;
float x = x-coordinate;
float y = y-coordinate;
float z = z-coordinate;

optional float/string h = optional float/string health;
optional float/string d = optional float/string density;
optional float/string s = optional float/string size;
}

//derived jaw
{
	
}

//derived spine
{
	
}

//derived vertebrae
{
	
}

//derived specific vertebrae
{
	
}

//derived shoulder
{
	
}

//derived elbows
{
	
}

//derived wrists
{
	
}

//derived knuckles
{
	
}

//derived knuckletypes
{
	
}

//derived hips
{
	
}

//derived knees
{
	
}

//derived ankles
{
	
}

//derived toejoints
{
	
}

//derived toejoint types

//l and r sides

//each class has l and r variables declared

//each might have attributes health, density, coordinates, size

//will need getloc(device/wrapper float x, y, z)


//bones
{
	
}

//cranium/skull
{
	
}

//jaw
{
	
}

//sternum
{
	
}

//upper arm
{
	
}

//forearm
{
	
}

//vertebrae
{
	
}

//hand bones
{
	
}

//finger bones
{
	
}

//pelvis
{
	
}

//upper leg
{
	
}

//lower leg
{
	
}

//ankle
{
	
}

//foot bones
{
	
}

//toe bones
{
	
}

