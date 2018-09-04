#include "Sensor.h"
#include "Connected.h"
#include "Connecting.h"
#include "Disconnected.h"
#include "Disconnecting.h"
#include "Faulted.h"

namespace Efficio
{
	Sensor::Sensor() : status(SensorStatus::Uninitialized) { }

	SensorStatus Sensor::GetStatus() { return status; }

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

	void Sensor::HandleConnectionStatus(Efficio::Frame* frame)
	{
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
				frame->AddEvent(std::shared_ptr<Event>(new Faulted(SensorInformation)));
				break;
			case SensorStatus::Connected:
				frame->AddEvent(std::shared_ptr<Event>(new Connected(SensorInformation)));
				break;
			case SensorStatus::Disconnected:
				frame->AddEvent(std::shared_ptr<Event>(new Disconnected(SensorInformation)));
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
	}

	Frame Sensor::GetFrame()
	{
		Efficio::Frame frame;

		PreGetFrame();

		HandleConnectionStatus(&frame);

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

	SensorInformation Sensor::GetSensorInformation() { return SensorInformation; }

	void Sensor::SetStatus(SensorStatus status)
	{
		connectionStatusChanged = true;
		Sensor::status = status;
	}
}