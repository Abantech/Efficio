#pragma once
#include "Frame.h"
#include "DeviceConfiguration.h"
#include "Vector3.h"
#include "Leap.h"
#include "Sensor.h"
#include <memory>
#include "Event.h"
#include "HistoricalFrameCollection.h"
#include "InputRecognitionEngine.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

using namespace std;

extern "C" 
{
	namespace Efficio
	{
		/// Efficio engine for retrieving processed frames.
		extern class DLLEXPORT Engine
		{
		public:
			Engine();
			~Engine();

			void Start();

			/// Gets the current {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			std::shared_ptr<Efficio::Frame> GetFrame();

			/// Gets the historical {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			std::shared_ptr<Efficio::Frame> GetFrame(int count);

			/// The device configuration for Efficio.
			Efficio::Configuration::DeviceConfiguration DeviceConfiguration;

		private:
			bool started;
			std::vector<Efficio::Sensors::Sensor*> sensors;
			InputRecognition::InputRecognitionEngine ire;
			HistoricalFrameCollection historicalFrames;
			int frameID;
		};
	}
}