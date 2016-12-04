// EfficioRuntime.Experimentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int main()
{
	auto engine = new Efficio::Engine();
	auto f = engine->Start();

	while (true)
	{
		auto frame = engine->GetFrame();
		auto events = frame->GetEvents();

		for (size_t i = 0; i < events.size(); i++)
		{
			auto ev = events.at(i);
			std::string evName;

			switch (ev->GetEventType())
			{
			case Efficio::Events::EventType::SensorConnected:
			{
				evName = "Sensor Connected";
				break;
			}
			case Efficio::Events::EventType::SensorDisconnected:
			{
				evName = "Sensor Disconnected";
				break;
			}
			case Efficio::Events::EventType::Pinch:
			{
				evName = "Pinch";
				break;
			}
			default:
				break;
			}

			cout << ev->ID << ": " << evName << "\n";
		}
	}
}

