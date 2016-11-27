#include "HistoricalFrameCollection.h"
#include <algorithm>

namespace Efficio
{
	HistoricalFrameCollection::HistoricalFrameCollection()
	{
	}

	HistoricalFrameCollection::~HistoricalFrameCollection()
	{
	}

	void HistoricalFrameCollection::AddFrame(std::shared_ptr<Frame> frame)
	{
		std::rotate(historicalFrames.rbegin(), historicalFrames.rbegin() + 1, historicalFrames.rend());
		historicalFrames.at(0) = frame;
	}

	std::shared_ptr<Frame> HistoricalFrameCollection::GetFrame(int countBack)
	{
		std::shared_ptr<Frame> frame = NULL;

		if (countBack > 0)
		{
			frame = historicalFrames.at(countBack - 1);
		}

		return frame;
	}
}