#include "Frame.h"
//#include "Leap.h"
#include <vector>
#include "Vector3.h"

using namespace std;


Efficio::Frame::Frame() { //constructor
	//There seem to be several options depending on the mechanics and preferences of generating variables from sensor input data
	//Leap.h likely needed for input data specific to each HandJoint
	//option: iterate for P values from array or other input data structure

	//DIP lh2DIP();
	//DIP lh3DIP();
	//DIP lh4DIP();
	//DIP lh5DIP();

	//DIP rh2DIP();
	//DIP rh3DIP();
	//DIP rh4DIP();
	//DIP rh5DIP();

	//PIP lh2PIP();
	//PIP lh3PIP();
	//PIP lh4PIP();
	//PIP lh5PIP();

	//PIP rh2PIP();
	//PIP rh3PIP();
	//PIP rh4PIP();
	//PIP rh5PIP();

	//MCP lh2MCP();
	//MCP lh3MCP();
	//MCP lh4MCP();
	//MCP lh5MCP();

	//MCP rh2MCP();
	//MCP rh3MCP();
	//MCP rh4MCP();
	//MCP rh5MCP();

	//Note single thumb joint design:
	//IPCMC lh1IPCMC();
	//IPCMC rh1MIPCMC();



	//vector option hjvec (hand joint vector) (27 elements)
	//vector<vector<vector<float>>> hjvec;
	//for(int i=0; i<27; ++i){
	//for(int j=0; j<27; ++j){
	//for(int k=0; k<27; ++k){
	//hjvec.push_back<i<j<k>>>;
	//}}}

	//array option hjarray (27 elements)
	//float hjarray[27][3] = {{0}};
	//Vector3.X()][Vector3.Y()][Vector3.Z()]
	//for(int i=0; i<27; ++i){
	//for(int j=0; j<3; ++j){
	//if(i==0)
	//hjarray[i][j] = {Vector3.X()};
	//if(j==1)
	//hjarray[i][j] = {Vector3.Y()};
	//if(k==2)
	//hjarray[i][j] = {Vector3.Z()};

	//map option hjmap (27 elements). Key value can be strings, such as lh2PIP, indicating joint hand and name, for future logic.
	//unordered_multimap(string, unordered_multimap(float, unordered_multimap(float, float))) hjmap;
	//for(int i=0; i<27; ++i){
	//for(int j=0; j<27; ++j){
	//for(int k=0; k<27; ++k){
	//hjmap.insert(i(j(k)));
	//}}}

	//NEXT: make compilable with Vector3, select, and connect to sensor device input program


}

Efficio::Frame::~Frame() { //destructor

}

/*sample main() below - might be pasted into MainPage.cpp
*ptr1
//P should be received from Vector3 for each (for_each, for loop, and/or while loop) HandJoint

//To call any member function: ptr1->memberfunction;
*/
