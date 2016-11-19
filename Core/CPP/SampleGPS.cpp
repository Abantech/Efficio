#include "SampleGPS.h"

Efficio::DeviceStatus Efficio::Sensors::SampleGPS::Status()
{
	return Efficio::DeviceStatus();
}

Efficio::TrackingType Efficio::Sensors::SampleGPS::TrackingTypes()
{
	return Efficio::TrackingType();
}

void Efficio::Sensors::SampleGPS::Connect()
{
}

void Efficio::Sensors::SampleGPS::Disconnect()
{
}

bool Efficio::Sensors::SampleGPS::HasFrame()
{
	return false;
}

Efficio::Frame Efficio::Sensors::SampleGPS::GetFrame()
{
	return Efficio::Frame();
}
