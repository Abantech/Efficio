// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "Engine.h"
#include "Pinch.h"

int main()
{
	Efficio::Engine engine;

	engine.Start();

	while (true)
	{
		auto ev = engine.GetFrame()->GetEvents()[0];
		

	}
}

