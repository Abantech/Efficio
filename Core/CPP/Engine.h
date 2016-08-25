#pragma once
#include "EfficioFrame.h"
#include "DeviceConfiguration.h"
#include "Leap.h"
#include <memory>

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

			/// Gets the current {@link Efficio::Frame frame} from the runtime.
			/// @return the current frame.
			Efficio::EfficioFrame GetFrame();

			/// The device configuration for Efficio.
			Efficio::Configuration::DeviceConfiguration DeviceConfiguration;

		private:
			bool started;

			Leap::Controller* controller;
		};
	}
}