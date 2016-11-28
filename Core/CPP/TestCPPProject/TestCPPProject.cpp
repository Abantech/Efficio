// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "Engine.h"
#include "HandData.h"
#include <iostream>


int main()
{
	Efficio::Engine engine;

	engine.Start();

	while (true)
	{
		auto frame = engine.GetFrame();
		auto events = frame->GetEvents();

		
		if (events.size() > 0)
		{
			cout << "SUCCESS";
		}
	}
}

