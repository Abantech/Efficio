#pragma once
#include "Finger.h"
#include "Joint.h"
#include "BodySide.h"
#include <array>

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// Representation of the human hand
			class Hand
			{

			public:
				Hand();
				Hand(BodySide side, std::array<Finger, 5> fingers, float confidence = -1);
				~Hand();

				/// The side of the body
				BodySide Side;

				/// <summary>
				/// How confident we are with a given hand pose.
				/// The confidence level ranges between 0.0 and 1.0 inclusive. -1 indicates that no confidence value was supplied.
				/// </summary>
				float Confidence;

				size_t ID;

				std::string Source;

				/// The fingers of the hand
				std::array<Finger, 5> Fingers;
			};
		}
	}
}