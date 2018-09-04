#pragma once

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Enumeration containing all of the face tracking point
			enum class FacePointType {
				None = -1,
				EyeLeft = 0,
				EyeRight = 1,
				Nose = 2,
				MouthCornerLeft = 3,
				MouthCornerRight = 4,
			};
		}
	}
}