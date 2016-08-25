#include "RightHandThumbAndIndexPinch.h"
#include "Enumerations.h"
namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hand {
				RightHandThumbAndIndexPinch::RightHandThumbAndIndexPinch(Vector3 position) : Pinch(Efficio::Body::BodySide::Right, position)
				{
					Finger1 = Efficio::Body::Finger::Thumb;
					Finger2 = Efficio::Body::Finger::Index;
				}
				RightHandThumbAndIndexPinch::~RightHandThumbAndIndexPinch()
				{
				}
				void RightHandThumbAndIndexPinch::Eh()
				{
				}
			}
		}
	}
}