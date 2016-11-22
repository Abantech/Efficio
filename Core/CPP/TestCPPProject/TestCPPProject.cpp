// TestCPPProject.cpp : Defines the entry point for the console application.
//

#include "Engine.h"
#include "HandData.h"
#include <iostream>


int main()
{
	Efficio::Engine engine;

	engine.Start();

	while (true)
	{
		auto frame = engine.GetFrame();
		auto data = frame->GetDataOfType(Efficio::Data::DataType::Hand);

		if (data.size() > 0)
		{
			auto handData = dynamic_cast<Efficio::Data::Body::HandData*>(data.at(0).get());

			if (handData->Hands.size() > 0)
			{
				auto hands = handData->Hands;

				for (size_t i = 0; i < hands.size(); i++)
				{
					auto hand = hands[i]; 
					if (hand.Fingers[0].Tip.DistanceTo(hand.Fingers[1].Tip) < 25)
					{
						auto side = (hand.Side == Efficio::Models::Body::BodySide::Left ? "left" : "right");
						std::cout << side;
						std::cout << +" pinch\r\n";

						auto test = hand.Fingers[0].Hand->Fingers[0].Hand;
						auto testFingers = test->Fingers;
					}
				}
			}
		}
	}
}

