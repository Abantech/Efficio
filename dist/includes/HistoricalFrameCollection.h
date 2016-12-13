#pragma once

#include "Frame.h"
#include <array>
#include <memory>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Collection of historical Efficio frames
	extern class DLLEXPORT HistoricalFrameCollection 
	{
	public:
		HistoricalFrameCollection();
		~HistoricalFrameCollection();

		/// Adds an Efficio frame to the history
		void AddFrame(std::shared_ptr<Efficio::Frame> frame);

		/// Gets a historical Efficio frame
		std::shared_ptr<Efficio::Frame> GetFrame(int countBack);
	
		std::array<std::shared_ptr<Efficio::Frame>, 120> historicalFrames;
	};
}