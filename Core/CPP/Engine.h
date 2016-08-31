#pragma once
#include "EfficioFrame.h"
#include "DeviceConfiguration.h"
#include "Leap.h"
#include <memory>
#include "Event.h"
#include "HistoricalFrameCollection.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#endif

extern "C" {
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
			Efficio::EfficioFrame* GetFrame();

			/// Gets the historical {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			Efficio::EfficioFrame* GetFrame(int count);

			/// The device configuration for Efficio.
			Efficio::Configuration::DeviceConfiguration DeviceConfiguration;

		private:
			bool started;
			Leap::Controller* controller;
			HistoricalFrameCollection historicalFrames;
			int frameID;
			std::vector<std::shared_ptr<Efficio::Events::Event>> lastFrameEvents;
		};
	}
}