#pragma once
#include "EfficioFrame.h"
#include "DeviceConfiguration.h"
#include "Leap.h"
#include <memory>
#include "Event.h"
#include "HistoricalFrameCollection.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
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
			std::shared_ptr<Efficio::EfficioFrame> GetFrame();

			/// Gets the historical {@link Efficio::EfficioFrame frame} from the runtime.
			/// @return the current frame.
			std::shared_ptr<Efficio::EfficioFrame> GetFrame(int count);

			/// The device configuration for Efficio.
			Efficio::Configuration::DeviceConfiguration DeviceConfiguration;

		private:
			bool started;
			Leap::Controller* controller;
			HistoricalFrameCollection historicalFrames;
			int frameID;
		};
	}
}