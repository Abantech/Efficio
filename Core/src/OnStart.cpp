#include "OnStart.h"
namespace Efficio
{
	namespace Events
	{
		namespace Internal
		{
			OnStart::OnStart()
			{
			}
			OnStart::~OnStart()
			{
			}
			Efficio::Events::EventType OnStart::GetEventType()
			{
				return Efficio::Events::EventType::EfficioStarted;
			}
		}
	}
}