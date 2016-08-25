#pragma once

#include "Pinch.h"
#include "Enumerations.h"


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hand {
				class RightHandThumbAndIndexPinch : public Pinch
				{
				public:
					RightHandThumbAndIndexPinch(Vector3 position);
					~RightHandThumbAndIndexPinch();
					void Eh();
				private:

				};
			}
		}
	}
}