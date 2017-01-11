#include "HandRecognitionProcessor.h"
#include "HandData.h"

#include "PinchDetector.h"

namespace Efficio
{
	namespace InputRecognition
	{
		namespace Body
		{
			namespace Hands
			{
				HandRecognitionProcessor::HandRecognitionProcessor() : singleHandDetectors()
				{
					singleHandDetectors.push_back(std::shared_ptr<Hands::SingleHandGestureDetector>(new Hands::PinchDetector()));
				}
				HandRecognitionProcessor::~HandRecognitionProcessor()
				{
				}
				std::vector<std::shared_ptr<Events::Event>> HandRecognitionProcessor::DetectEvents(Frame frame)
				{
					std::vector<std::shared_ptr<Events::Event>> events;

					// TODO detect events
					auto data = frame.GetData();

					if (data.size() > 0)
					{
						for (size_t i = 0; i < data.size(); i++)
						{
							auto handData = dynamic_cast<Data::Body::HandData*>(data.at(i).get());

							if (handData)
							{
								for (size_t j = 0; j < handData->Hands.size(); j++)
								{
									auto hand = handData->Hands.at(j);

									for (size_t k = 0; k < singleHandDetectors.size(); k++)
									{
										auto detected = singleHandDetectors.at(k)->Detect(hand);

										for (size_t L = 0; L < detected.size(); L++)
										{
											events.push_back(detected[L]);
										}
									}
								}
							}
						}
					}

					return events;
				}

				Efficio::Data::DataType HandRecognitionProcessor::GetDataType()
				{
					return Efficio::Data::DataType::Hand;
				}
			}
		}
	}
}