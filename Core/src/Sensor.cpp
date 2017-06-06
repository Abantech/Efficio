#include "..\include\Sensor.h"
#include "..\include\Connected.h"
#include "..\include\Connecting.h"
#include "..\include\Disconnected.h"
#include "..\include\Disconnecting.h"
#include "..\include\Faulted.h"

namespace Efficio
{
	Sensor::Sensor() : status(SensorStatus::Uninitialized)
	{
	}

	SensorStatus Sensor::GetStatus()
	{
		return status;
	}

	Frame Sensor::Connect()
	{
		Frame frame;

		// Indicate the connection state has changed
		connectionStatusChanged = true;

		// Set the status to "Connecting"
		status = SensorStatus::Connecting;

		// Add message that the sensor is connecting
		frame.AddEvent(std::shared_ptr<Event>(new Connecting(SensorInformation)));

		return frame;
	}

	Frame Sensor::Disconnect()
	{
		Frame frame;

		// Indicate the connection state has changed
		connectionStatusChanged = true;

		// Set the status to "Disconnected"
		status = SensorStatus::Disconnecting;

		// Add message that the sensor is disconnecting
		frame.AddEvent(std::shared_ptr<Event>(new Disconnecting(SensorInformation)));

		return frame;
	}

	Frame Sensor::GetFrame()
	{
		Efficio::Frame frame;

		PreGetFrame();

		if (IsConnected())
		{
			if (status != SensorStatus::Connected)
			{
				SetStatus(SensorStatus::Connected);
			}
		}
		else
		{
			if (status != SensorStatus::Disconnected)
			{
				SetStatus(SensorStatus::Disconnected);
			}
		}

		if (connectionStatusChanged)
		{
			switch (status)
			{
			case SensorStatus::Faulted:
				frame.AddEvent(std::shared_ptr<Event>(new Faulted(SensorInformation)));
				break;
			case SensorStatus::Connected:
				frame.AddEvent(std::shared_ptr<Event>(new Connected(SensorInformation)));
				break;
			case SensorStatus::Disconnected:
				frame.AddEvent(std::shared_ptr<Event>(new Disconnected(SensorInformation)));
				break;
			case SensorStatus::Disabled:
			case SensorStatus::Uninitialized:
			case SensorStatus::Unknown:
			case SensorStatus::Connecting:
			case SensorStatus::Disconnecting:
			default:
				break;
			}

			connectionStatusChanged = false;
		}

		// Check if new frame is available. If not, merge previously calculated frame with base frame
		if (!HasFrame())
		{
			frame.AddFrame(LastEfficioFrame);
		}
		else
		{
			// Create temporary frame
			Frame tempFrame;

			tempFrame.AddData(GetData());
			tempFrame.AddEvents(GetEvents());

			LastEfficioFrame = tempFrame;

			frame.AddFrame(tempFrame);
		}

		PostGetFrame();

		return frame;
	}

	std::string Sensor::GetSource()
	{
		return SensorInformation.Name;
	}

	SensorInformation Sensor::GetSensorInformation()
	{
		return SensorInformation;
	}

	void Sensor::SetStatus(SensorStatus status)
	{
		connectionStatusChanged = true;
		Sensor::status = status;
	}
}