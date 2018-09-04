#pragma once

#include "ImageData.h"

namespace Efficio
{
	namespace Models
	{
		namespace AudioVisual
		{
			/// Any sensor which can feed image data into Efficio
			class IImageSensor
			{
			public:
				IImageSensor() {};
				~IImageSensor() {};

				virtual void EnableImageTracking(bool enable) = 0;
			protected:
				virtual ImageData GetImageData() = 0;
			};
		}
	}
}