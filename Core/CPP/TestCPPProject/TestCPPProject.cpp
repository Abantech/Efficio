// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int main()
{
	Efficio::Engine engine;

	engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

	engine.Start();

	while (true)
	{
		auto frame = engine.GetFrame();

		auto frame2 = engine.GetFrame(10);

		if (frame->GetEvents().size() > 0) {
			int i = 0;
		}
	}
}

