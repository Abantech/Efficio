#pragma once

#include "Frame.h"
#include <array>
#include <memory>

namespace Efficio
{
	/// Collection of historical Efficio frames
	class HistoricalFrameCollection
	{
	public:
		HistoricalFrameCollection();
		~HistoricalFrameCollection();

		/// Adds an Efficio frame to the history
		void AddFrame(std::shared_ptr<Frame> frame);

		/// Gets a historical Efficio frame
		std::shared_ptr<Frame> GetFrame(int countBack);

		/// The historical frames
		std::array<std::shared_ptr<Frame>, 120> historicalFrames;
	};
}