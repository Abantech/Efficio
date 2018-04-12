#include "Engine.h"
#include "PinchEvent.h"
#include "BodySide.h"
#include "PointEvent.h"
#include "Connected.h"
#include "FingerType.h"
#include <iostream>
#include "Message.h"

void PrintOnPinch(Efficio::Message message)
{
	auto pinch = dynamic_cast<Efficio::Recognition::Body::PinchEvent*>(message.GetEvent().get());
	if (pinch->Finger1.FingerType == Efficio::Models::Body::FingerType::Thumb && pinch->Finger2.FingerType == Efficio::Models::Body::FingerType::Index)
	{
		cout << "Pinch point: (" << pinch->Midpoint().x() << ", " << pinch->Midpoint().y() << ", " << pinch->Midpoint().z() << ")\n";
	}
}

void PrintOnSensorConnected(Efficio::Message message)
{
	auto con = dynamic_cast<Efficio::Connected*>(message.GetEvent().get());
	cout << con->SensorInformation.Name << " Connected";
}

void PrintOnPoint(Efficio::Message message)
{
	auto point = dynamic_cast<Efficio::Recognition::Body::PointEvent*>(message.GetEvent().get());
	cout << (point->Side == Efficio::Models::Body::BodySide::Right ? "Right" : "Left") << " Point Detected. Tip at (" << point->Finger.Tip.Position.x() << ", " << point->Finger.Tip.Position.y() << ", " << point->Finger.Tip.Position.z() << ")\n";
	cout << "Point Direction: (" << point->PointDirection.x() << ", " << point->PointDirection.y() << ", " << point->PointDirection.z() << ")\n";
}

int main(int argc, char** argv) {
	Efficio::Engine engine;

	// Register Events
	engine.MessageBus->AddReceiver(Efficio::Recognition::Body::PinchEvent::EventType, std::function<void(Efficio::Message)>(PrintOnPinch));
	engine.MessageBus->AddReceiver(Efficio::Connected::EventType, std::function<void(Efficio::Message)>(PrintOnSensorConnected));
	engine.MessageBus->AddReceiver(Efficio::Recognition::Body::PointEvent::EventType, std::function<void(Efficio::Message)>(PrintOnPoint));
	
	// Start your engines!
	engine.Start();

	while (true)
	{
		// Get Frames
		auto frame = engine.GetFrame();

		// Magic happens here

		// Release the frame into the wild
		engine.ReleaseFrame();
	}

	return 0;
}