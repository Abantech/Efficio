#include "HandSupine.h"
namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				HandSupine::HandSupine(std::string source, Efficio::Models::Body::BodySide side) : Side(side), DiscreteGesture(source)
				{
				}
				HandSupine::~HandSupine()
				{
				}
				Efficio::Events::EventType HandSupine::GetEventType()
				{
					return Efficio::Events::EventType::HandSupine;
				}
			}
		}
	}
}