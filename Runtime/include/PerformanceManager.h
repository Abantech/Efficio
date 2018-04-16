#pragma once

#include <memory>

namespace Efficio
{
	class PerformanceManager
	{
		friend class Engine;
	public:
		~PerformanceManager() {};

		float GetFrameRate();

		static std::shared_ptr<PerformanceManager> Current();
	private:
		float deltaTimeSum;
		PerformanceManager() : deltaTimeSum(0) { }
		PerformanceManager(PerformanceManager const&) = delete;
		void operator=(PerformanceManager const&) = delete;
	};
}