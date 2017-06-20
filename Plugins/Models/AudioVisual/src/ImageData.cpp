#include "ImageData.h"

namespace Efficio
{
	namespace Models
	{
		namespace AudioVisual
		{
			ImageData::ImageData() { }

			ImageData::ImageData(std::vector<Image> images) : Images(images) { }

			ImageData::~ImageData() { }
		}
	}
}