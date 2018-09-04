#include "Face.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			Face::Face() { }
			Face::Face(Vector2 eyeLeft, Vector2 eyeRight, Vector2 nose, Vector2 mouthCornerLeft, Vector2 mouthCornerRight) : 
				eyeLeft(eyeLeft), eyeRight(eyeRight), nose(nose), mouthCornerLeft(mouthCornerLeft), mouthCornerRight(mouthCornerRight) { }
			Face::~Face() { }

			Vector2 Face::EyeLeft() { return this->eyeLeft; }
			Vector2 Face::EyeRigh() { return this->eyeRight; }
			Vector2 Face::Nose() { return this->nose; }
			Vector2 Face::MouthCornerLeft() { return this->mouthCornerLeft; }
			Vector2 Face::MouthCornerRight() { return this->mouthCornerRight; }

			Vector4 Face::Rotation() { return this->rotation; }

			ULONG32 Face::TrackingId() { return this->trackingId; }
		}
	}
}