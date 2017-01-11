#include "SingleHandGesture.h"
#include "BodySide.h"

namespace Efficio 
{
	namespace InputRecognition
	{
		namespace Body
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