#include "LeapMotionDevice.h"
#include <array>

namespace Efficio
{
	LeapMotionDevice::LeapMotionDevice(bool enabled) : Device(enabled)
	{
		if (Enabled)
		{
			controller = new Leap::Controller();
			controller->setPaused(true);
			ID = controller->devices()[0].serialNumber();
		}
	}

	LeapMotionDevice::~LeapMotionDevice()
	{
		delete controller;
	}

	Efficio::DeviceStatus LeapMotionDevice::Status()
	{
		Efficio::DeviceStatus status = DeviceStatus::Unknown;

		if (!Enabled)
		{
			status = Efficio::DeviceStatus::Disabled;
		}
		else
		{
			if (!controller)
			{
				status = Efficio::DeviceStatus::Faulted;
			}
			else
			{
				if (controller->isPaused())
				{
					status = Efficio::DeviceStatus::Disconnected;
				}
				else
				{
					status = Efficio::DeviceStatus::Connected;
				}
			}
		}

		return status;
	}

	Efficio::TrackingType LeapMotionDevice::TrackingTypes()
	{
		return Efficio::TrackingType::Hand;
	}

	void LeapMotionDevice::Connect()
	{
		if (Enabled)
		{
			controller->setPaused(false);
		}
	}

	void LeapMotionDevice::Disconnect()
	{
		if (Enabled)
		{
			controller->setPaused(true);
		}
	}

	bool LeapMotionDevice::HasFrame()
	{
		bool sameFrame = true;

		if (Enabled)
		{
			currentFrame = controller->frame();

			sameFrame = currentFrame.id() == lastFrame.id();

			lastFrame = currentFrame;
		}

		return sameFrame;
	}

	Efficio::Frame LeapMotionDevice::GetFrame()
	{
		Efficio::Frame frame;

		if (Enabled)
		{
			auto leapFrame = controller->frame();

			if (leapFrame.isValid())
			{
				if (leapFrame.hands().count() > 0)
				{
				}
			}
		}

		return frame;
	}
}