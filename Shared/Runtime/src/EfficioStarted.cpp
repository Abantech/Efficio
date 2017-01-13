#include "EfficioStarted.h"
namespace Efficio
{
	namespace Events
	{
		namespace Internal
		{
			EfficioStarted::EfficioStarted(): Event("EfficioInternal")
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
