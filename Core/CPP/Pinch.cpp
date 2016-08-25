#include "Pinch.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Human
		{
			namespace Hand {

				Pinch::Pinch(Efficio::Body::BodySide side, Vector3 position) : Side(side), Position(position.X(), position.Y(), position.Z())
				{
				}

				Pinch::~Pinch()
				{
				}

				bool Pinch::Detect(Leap::Hand hand)
				{
					if (hand.fingers()[0].stabilizedTipPosition().distanceTo(hand.fingers()[1].stabilizedTipPosition()) < 25)
					{
						Body::BodySide side = hand.isLeft() ? Body::BodySide::Left : Body::BodySide::Right;
						auto leapPos = hand.fingers()[0].stabilizedTipPosition();

				/*		auto ib = frame.interactionBox();
						leapPos = ib.normalizePoint(leapPos);*/

						Vector3 position(leapPos.x, leapPos.y, leapPos.z);
						Pinch* pinch = new Pinch(side, position);

						pinch->Detected();

						return true;
					}

					return false;
				}
				/*bool Pinch::operator==(const Pinch & rhs)
				{
					return (this->Finger1 == rhs.Finger1) &&
						(this->Finger2 == rhs.Finger2) &&
						(this->ID == rhs.ID) &&
						(this->Side == rhs.Side);
				}*/
			}
		}
	}
}