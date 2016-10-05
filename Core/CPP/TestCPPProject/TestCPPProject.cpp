// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "Engine.h"
#include "Pinch.h"

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
			auto ev = frame->GetEvents()[0];
			ev->GetEventType();
			auto pinch = dynamic_cast<Efficio::InputRecognition::Human::Hands::Pinch*>(ev.get());

			int i = 0;
		}
	}
}

