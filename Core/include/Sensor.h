#pragma once

#include <string>
#include "Frame.h"
#include "SensorStatus.h"
#include "SensorInformation.h"

namespace Efficio
{
	/// Any sensor which can feed data into Efficio
	class Sensor
	{
	public:
		Sensor();
		~Sensor() {};

		/// The type of data the device is able to track
		virtual std::string TrackingType() = 0;

		// Virtual Methods
		/// Connects the device
		virtual Frame Connect();

		/// Disconnects the device
		virtual Frame Disconnect();

		/// The unique ID of the device
		std::string ID;

		/// A Boolean indicating whether or not the device is enabled
		bool Enabled;

		/// The status of the device
		SensorStatus GetStatus();

		/// Gets the current frame from the device
		Efficio::Frame GetFrame();

		/// Gets information about the sensor
		virtual SensorInformation GetSensorInformation();

	protected:
		/// Gets the last frame produced by the sensor
		Frame LastEfficioFrame;

		/// Information about the sensor
		SensorInformation SensorInformation;

		/// Sets the status of the sensor
		void SetStatus(SensorStatus status);

		/// Gets data from the sensor
		virtual std::vector<std::shared_ptr<Data>> GetData() = 0;

		/// Gets events from the sensor
		virtual std::vector<std::shared_ptr<Event>> GetEvents() = 0;

		/// A Boolean indicating whether or not the device is connected and ready to feed data into Efficio
		virtual bool IsConnected() = 0;

		/// A Boolean indicating whether or not the device has a new frame for Efficio
		virtual bool HasFrame() = 0;

		/// A function that gets called before a frame is requested
		virtual void PreGetFrame() = 0;

		/// A function that gets called after a frame is requested
		virtual void PostGetFrame() = 0;

	private:
		SensorStatus status;
		bool connectionStatusChanged;
	};
}