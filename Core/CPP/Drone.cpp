#include "Drone.h"
#include "SampleAltimeter.h"
#include "SampleGPS.h"

Efficio::Models::Drone::Drone()
{
	// Register drone's GPS
	Efficio::Sensors::SampleGPS droneGPS;
	Sensors.push_back(&droneGPS);

	//Register drone's altimeter
	Efficio::Sensors::SampleAltimeter droneAltimeter;
	Sensors.push_back(&droneAltimeter);
}

Efficio::Frame Efficio::Models::Drone::GetFrame()
{
	Efficio::Frame frame;

	for each (Efficio::Sensors::Sensor* sensor in Sensors)
	{
		if (Efficio::Sensors::Altimeter* j = dynamic_cast<Efficio::Sensors::Altimeter*>(sensor)) {
			auto altData = j->GetAltitude();
			frame.AddData(&altData);
		}
		else if (Efficio::Sensors::LocationSensor* j = dynamic_cast<Efficio::Sensors::LocationSensor*>(sensor)) {
			auto locData = j->GetLocation();
			frame.AddData(&locData);
		}
	}

	return frame;
}
