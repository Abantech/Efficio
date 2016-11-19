#include "SampleAltimeter.h"

Efficio::DeviceStatus Efficio::Sensors::SampleAltimeter::Status()
{
	return Efficio::DeviceStatus();
}

Efficio::TrackingType Efficio::Sensors::SampleAltimeter::TrackingTypes()
{
	return Efficio::TrackingType();
}

void Efficio::Sensors::SampleAltimeter::Connect()
{
}

void Efficio::Sensors::SampleAltimeter::Disconnect()
{
}

bool Efficio::Sensors::SampleAltimeter::HasFrame()
{
	return false;
}

Efficio::Frame Efficio::Sensors::SampleAltimeter::GetFrame()
{
	return Efficio::Frame();
}
