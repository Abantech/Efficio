#include "Image.h"

namespace Efficio
{
	namespace Models
	{
		namespace AudioVisual
		{
			Image::Image() : Image(0, 0, 0) { }

			Image::Image(int height, int width, int depth) : Image(height, width, depth, nullptr) { }

			Image::Image(int height, int width, int depth, const unsigned char* data) : Height(height), Width(width), Depth(depth), Data(data) { }

			Image::~Image() { }
		}
	}
}