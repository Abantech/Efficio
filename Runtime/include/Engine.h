#pragma once

#include "Frame.h"
#include "Asset.h"
#include <memory>
#include "Event.h"
#include "HistoricalFrameCollection.h"
#include "InputRecognitionEngine.h"
#include "MessageBus.h"
#include "PerformanceManager.h"
#include "AssetManager.h"

using namespace std;

namespace Efficio
{
	/// Efficio engine for retrieving processed frames.
	class Engine
	{
	public:
		Engine();
		~Engine();
		
		/// Starts the engine
		Frame Start();

		/// Gets the current {@link Efficio::Frame frame} from the runtime.
		/// @return the current frame.
		std::shared_ptr<Frame> GetFrame();

		/// Gets the historical {@link Efficio::Frame frame} from the runtime.
		/// @return the historical frame.
		std::shared_ptr<Frame> GetFrame(int count);
		
		std::shared_ptr<Efficio::MessageBus> MessageBus;

		void ReleaseFrame();

		std::shared_ptr<Efficio::PerformanceManager> PerformanceManager;
		std::shared_ptr<Efficio::AssetManager> AssetManager;

	private:
		bool started;
		InputRecognitionEngine ire;
		HistoricalFrameCollection historicalFrames;
		int frameID;
	};
}