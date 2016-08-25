// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "RightHandThumbAndIndexPinch.h"
#include "Event.h"
#include "Gesture.h"
#include "DiscreteGesture.h"
#include "Pinch.h"

int main()
{
	Efficio::Engine engine;

	engine.DeviceConfiguration.LeapConfiguration.Enabled = true;

	engine.Start();

	while (true)
	{
		auto frame = engine.GetFrame();

		for (size_t i = 0; i < frame.GetEvents().size(); i++)
		{
			Efficio::Event* ev = frame.GetEvents().at(i).get();
			auto pinch = dynamic_cast<Efficio::InputRecognition::Human::Hand::RightHandThumbAndIndexPinch*>(ev);
			int j = 0;
		}
	}
}

