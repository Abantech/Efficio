#pragma once

#include "EfficioFrame.h"
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
		void AddFrame(std::shared_ptr<Efficio::EfficioFrame> frame);

		/// Gets a historical Efficio frame
		std::shared_ptr<Efficio::EfficioFrame> GetFrame(int countBack);
	
		std::array<std::shared_ptr<Efficio::EfficioFrame>, 59> historicalFrames;
	};
}