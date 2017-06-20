#pragma once

#include "Data.h"
#include "Image.h"
#include <vector>

namespace Efficio
{
	namespace Models
	{
		namespace AudioVisual 
		{
			class ImageData : public Data
			{
			public:
				ImageData();
				ImageData(std::vector<Image> images);
				~ImageData();

				std::vector<Image> Images;

				/// <summary>
				/// Gets the type of the data.
				/// </summary>
				/// <returns></returns>
				std::string GetDataType() { return "Image"; }
			};
		}
	}
}