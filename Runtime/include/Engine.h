#pragma once

#include "Frame.h"
#include "Asset.h"
#include <memory>
#include "Event.h"
#include "HistoricalFrameCollection.h"
#include "InputRecognitionEngine.h"
#include "MessageBus.h"

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

		/// Gets the frame rate at which Efficio is running
		float GetFrameRate();
		
		std::shared_ptr<Efficio::MessageBus> MessageBus;

		void ReleaseFrame();

	private:
		bool started;
		std::vector<Asset*> assets;
		InputRecognitionEngine ire;
		HistoricalFrameCollection historicalFrames;
		int frameID;

		float deltaTimeSum;
	};
}