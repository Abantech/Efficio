#include "EfficioStarted.h"
namespace Efficio
{
	namespace Events
	{
		namespace Internal
		{
			EfficioStarted::EfficioStarted()
			{
			}
			EfficioStarted::~EfficioStarted()
			{
			}
			EventType EfficioStarted::GetEventType()
			{
				return EventType::EfficioStarted;
			}
		}
	}
}
