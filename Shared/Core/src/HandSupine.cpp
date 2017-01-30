#include "HandSupine.h"
namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				HandSupine::HandSupine(std::string source, Efficio::Models::Body::BodySide side, int handID) : Side(side), DiscreteGesture(source), HandID(handID)
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