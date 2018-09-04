#pragma once

#include "Vector2.h"
#include "Vector4.h"

// https://docs.microsoft.com/en-us/previous-versions/windows/kinect/dn791565%28v%3dieb.10%29
namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Representation of the human face
			class Face
			{
			public:
				Face();
				Face(Vector2 eyeLeft, Vector2 eyeRight, Vector2 nose, Vector2 mouthCornerLeft, Vector2 mouthCornerRight);
				~Face();

				Vector2 EyeLeft();
				Vector2 EyeRigh();
				Vector2 Nose();
				Vector2 MouthCornerLeft();
				Vector2 MouthCornerRight();

				Vector4 Rotation();
				ULONG32 TrackingId();
			private:
				Vector4 rotation;
				ULONG32 trackingId;
				Vector2 eyeLeft;
				Vector2 eyeRight;
				Vector2 nose;
				Vector2 mouthCornerLeft;
				Vector2 mouthCornerRight;
			};
		}
	}
};