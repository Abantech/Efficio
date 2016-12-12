#pragma once

#include "Sensor.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Sensors 
	{
		namespace Body
		{
			/// <summary>
			/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
			/// </summary>
			/// <seealso cref="Sensor" />
			extern class DLLEXPORT Kinect : public Sensor
			{
			public:
				Kinect();
				~Kinect();

				// Inherited via Sensor
				virtual Sensors::TrackingType TrackingTypes() override;


			protected:

				// Inherited via Sensor
				virtual bool IsConnected() override;
				virtual std::vector<std::shared_ptr<Data::Data>> GetData() override;
				virtual std::vector<std::shared_ptr<Events::Event>> GetEvents() override;

				// Inherited via Sensor
				virtual Frame Connect() override;
				virtual Frame Disconnect() override;
				virtual bool HasFrame() override;
				virtual void PreGetFrame() override;
				virtual void PostGetFrame() override;
			};
		}
	}
}