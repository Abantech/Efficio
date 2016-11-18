#include "SingleHandGesture.h"
#include "BodySide.h"

namespace Efficio {
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hands
			{
				SingleHandGesture::SingleHandGesture(Efficio::Models::Body::BodySide side) : Side(side)
				{
				}
				SingleHandGesture::~SingleHandGesture()
				{
				}
			}
		}
	}
}