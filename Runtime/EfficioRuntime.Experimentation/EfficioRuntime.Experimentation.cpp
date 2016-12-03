// EfficioRuntime.Experimentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int main()
{
	auto engine = new Efficio::Engine();
	engine->Start();
	while (true)
	{
		auto frame = engine->GetFrame();

		if (frame->GetEvents().size() > 0)
		{
			auto ev = frame->GetEvents()[0];
		}
	}
}

