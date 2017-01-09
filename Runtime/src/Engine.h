#pragma once
#include "Frame.h"
#include "Vector3.h"
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

			Frame Start();

			/// Gets the current {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			std::shared_ptr<Frame> GetFrame();

			/// Gets the historical {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			std::shared_ptr<Frame> GetFrame(int count);

			float GetFrameRate();

		private:
			bool started;
			std::vector<Sensors::Sensor*> sensors;
			InputRecognition::InputRecognitionEngine ire;
			HistoricalFrameCollection historicalFrames;
			int frameID;

			float deltaTimeSum;
		};
	}
}