#include "PerformanceManager.h"

namespace Efficio
{
	std::shared_ptr<PerformanceManager> PerformanceManager::Current()
	{
		static std::shared_ptr<PerformanceManager> instance = std::shared_ptr<PerformanceManager>(new PerformanceManager());
		return instance;
	}

	float PerformanceManager::GetFrameRate() { return 1000 / (deltaTimeSum / 60); }
}