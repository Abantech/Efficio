#pragma once

namespace Efficio
{
	namespace Models
	{
		namespace AudioVisual
		{
			class Image
			{
			public:
				Image();
				Image(int length, int width, int depth);
				Image(int length, int width, int depth, const unsigned char* data);
				~Image();
				const int Height;
				const int Width;
				const int Depth;
				const unsigned char* Data;
			private:

			};
		}
	}
}