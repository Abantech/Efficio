#include "RealSenseSensor.h"

namespace Efficio
{
	namespace Assets
	{
		RealSenseSensor::RealSenseSensor() : sampleReader(NULL)
		{
			SensorInformation.Name = "Intel Realsense";
		}

		RealSenseSensor::~RealSenseSensor() { }

		std::string RealSenseSensor::TrackingType()
		{
			// TODO
			return "Hands";
		}

		Frame RealSenseSensor::Connect()
		{
			Frame frame = Sensor::Connect();

			session = PXCSession::CreateInstance();
			if (!session)
			{
				SetStatus(SensorStatus::Faulted);
				return frame;
			}

			senseManager = session->CreateSenseManager();
			if (!senseManager)
			{
				SetStatus(SensorStatus::Faulted);
				ReleaseAll();
				return frame;
			}

			EnableModule();

			auto message = senseManager->Init();
			if (message != PXC_STATUS_NO_ERROR)
			{
				SetStatus(SensorStatus::Faulted);
				ReleaseAll();
			}

			return frame;
		}

		Frame RealSenseSensor::Disconnect()
		{
			Frame frame = Sensor::Disconnect();

			ReleaseAll();

			return frame;
		}

		bool RealSenseSensor::HasFrame()
		{
			return IsConnected() && senseManager->AcquireFrame() == PXC_STATUS_NO_ERROR;
		}

		std::vector<std::shared_ptr<Data>> RealSenseSensor::GetData()
		{
			std::vector<std::shared_ptr<Data>> data;

			if (trackingHands)
			{
				auto dataSharedPtr = std::make_shared<Models::Body::HandData>(GetHandData());
				data.push_back(dataSharedPtr);
			}

			if (trackingFaces)
			{
				/*auto dataSharedPtr = std::make_shared<Models::Body::FaceData>(GetFaceData());
				data.push_back(dataSharedPtr);*/
			}

			if (trackingImages)
			{
				auto dataSharedPtr = std::make_shared<Models::AudioVisual::ImageData>(GetImageData());
				data.push_back(dataSharedPtr);
			}

			return data;
		}

		void RealSenseSensor::EnableHandTracking(bool enable)
		{
			trackingHands = enable;
		}

		void RealSenseSensor::EnableImageTracking(bool enable)
		{
			trackingImages = enable;
		}

		std::vector<std::shared_ptr<Event>> RealSenseSensor::GetEvents()
		{
			return std::vector<std::shared_ptr<Event>>();
		}

		bool RealSenseSensor::IsConnected()
		{
			if (senseManager)
			{
				return senseManager->IsConnected();
			}

			return false;
		}
		
		void RealSenseSensor::PreGetFrame()
		{
		}
		
		void RealSenseSensor::PostGetFrame()
		{
			if (senseManager)
			{
				senseManager->ReleaseFrame();
			}
		}

		void RealSenseSensor::ReleaseAll()
		{
			// Release Configurations
			if (handConfiguration)
			{
				handConfiguration->Release();
				handConfiguration = NULL;
			}

			//if (faceConfiguration)
			//{
			//	faceConfiguration->Release();
			//	faceConfiguration = NULL;
			//}

			// Release Outputs
			if (handDataOutput)
			{
				handDataOutput->Release();
				handDataOutput = NULL;
			}

			//if (faceDataOutput)
			//{
			//	faceDataOutput->Release();
			//	faceDataOutput = NULL;
			//}

			if (sampleReader)
			{
				sampleReader->Release();
				sampleReader = NULL;
			}

			if (senseManager)
			{
				senseManager->Close();
				senseManager->Release();
				senseManager = NULL;
			}
			if (session)
			{
				session->Release();
				session = NULL;
			}
		}

		void RealSenseSensor::EnableModule()
		{
			if (trackingHands)
			{
				if (senseManager->EnableHand(0) != PXC_STATUS_NO_ERROR)
				{
					SetStatus(SensorStatus::Faulted);
					ReleaseAll();
					return;
				}

				handModule = senseManager->QueryHand();
				if (!handModule)
				{
					SetStatus(SensorStatus::Faulted);
					ReleaseAll();
					return;
				}

				handDataOutput = handModule->CreateOutput();
				if (!handDataOutput)
				{
					SetStatus(SensorStatus::Faulted);
					ReleaseAll();
					return;
				}

				handConfiguration = handModule->CreateActiveConfiguration();
				if (!handConfiguration)
				{
					SetStatus(SensorStatus::Faulted);
					ReleaseAll();
					return;
				}

				handConfiguration->SetTrackingMode(PXCHandData::TRACKING_MODE_FULL_HAND);
			}

			if (trackingFaces)
			{
				/*if (senseManager->EnableFace(0) != PXC_STATUS_NO_ERROR)
				{
					SetStatus(Status::Faulted);
					ReleaseAll();
					return;
				}

				faceModule = senseManager->QueryFace();
				if (!faceModule)
				{
					SetStatus(Status::Faulted);
					ReleaseAll();
					return;
				}

				faceDataOutput = faceModule->CreateOutput();
				if (!faceDataOutput)
				{
					SetStatus(Status::Faulted);
					ReleaseAll();
					return;
				}

				faceConfiguration = faceModule->CreateActiveConfiguration();
				if (!faceConfiguration)
				{
					SetStatus(Status::Faulted);
					ReleaseAll();
					return;
				}

				faceConfiguration->SetTrackingMode(PXCFaceConfiguration::TrackingModeType::FACE_MODE_COLOR_PLUS_DEPTH);
				faceConfiguration->QueryExpressions()->Enable();
				faceConfiguration->QueryExpressions()->EnableAllExpressions();
				faceConfiguration->ApplyChanges();*/
			}

			if (trackingImages)
			{
				sampleReader = Intel::RealSense::SampleReader::Activate(senseManager);
				sampleReader->EnableStream(Intel::RealSense::StreamType::STREAM_TYPE_COLOR, 640, 480, 30);

			}
		}

		Models::Body::Hand RealSenseSensor::convertToEfficioHand(PXCHandData::IHand* hand)
		{
			Models::Body::BodySide side = hand->QueryBodySide() == PXCHandData::BODY_SIDE_LEFT ? Models::Body::BodySide::Left : Models::Body::BodySide::Right;

			std::vector<Models::Body::Finger> fingers;

			for (size_t i = 0; i < 5; i++)
			{
				PXCHandData::FingerType fingerType;
				Models::Body::FingerType efficioFingerType;

				PXCHandData::JointType tipType;
				PXCHandData::JointType dipType;
				PXCHandData::JointType pipType;
				PXCHandData::JointType mcpType;

				switch (i)
				{
				case 0:
					fingerType = PXCHandData::FingerType::FINGER_THUMB;
					efficioFingerType = Models::Body::FingerType::Thumb;
					tipType = PXCHandData::JointType::JOINT_THUMB_TIP;
					dipType = PXCHandData::JointType::JOINT_THUMB_JT2;
					pipType = PXCHandData::JointType::JOINT_THUMB_JT1;
					mcpType = PXCHandData::JointType::JOINT_THUMB_BASE;
					break;
				case 1:
					fingerType = PXCHandData::FingerType::FINGER_INDEX;
					efficioFingerType = Models::Body::FingerType::Index;
					tipType = PXCHandData::JointType::JOINT_INDEX_TIP;
					dipType = PXCHandData::JointType::JOINT_INDEX_JT2;
					pipType = PXCHandData::JointType::JOINT_INDEX_JT1;
					mcpType = PXCHandData::JointType::JOINT_INDEX_BASE;
					break;
				case 2:
					fingerType = PXCHandData::FingerType::FINGER_MIDDLE;
					efficioFingerType = Models::Body::FingerType::Middle;
					tipType = PXCHandData::JointType::JOINT_MIDDLE_TIP;
					dipType = PXCHandData::JointType::JOINT_MIDDLE_JT2;
					pipType = PXCHandData::JointType::JOINT_MIDDLE_JT1;
					mcpType = PXCHandData::JointType::JOINT_MIDDLE_BASE;
					break;
				case 3:
					fingerType = PXCHandData::FingerType::FINGER_RING;
					efficioFingerType = Models::Body::FingerType::Ring;
					tipType = PXCHandData::JointType::JOINT_RING_TIP;
					dipType = PXCHandData::JointType::JOINT_RING_JT2;
					pipType = PXCHandData::JointType::JOINT_RING_JT1;
					mcpType = PXCHandData::JointType::JOINT_RING_BASE;
					break;
				case 4:
					fingerType = PXCHandData::FingerType::FINGER_PINKY;
					efficioFingerType = Models::Body::FingerType::Pinky;
					tipType = PXCHandData::JointType::JOINT_PINKY_TIP;
					dipType = PXCHandData::JointType::JOINT_PINKY_JT2;
					pipType = PXCHandData::JointType::JOINT_PINKY_JT1;
					mcpType = PXCHandData::JointType::JOINT_PINKY_BASE;
					break;
				default:
					break;
				}

				PXCHandData::FingerData finger;
				hand->QueryFingerData(fingerType, finger);

				PXCHandData::JointData tip;
				PXCHandData::JointData dip;
				PXCHandData::JointData pip;
				PXCHandData::JointData mcp;

				hand->QueryTrackedJoint(tipType, tip);
				hand->QueryTrackedJoint(dipType, dip);
				hand->QueryTrackedJoint(pipType, pip);
				hand->QueryTrackedJoint(mcpType, mcp);


				fingers.push_back(convertToEfficioFinger(side, efficioFingerType, finger, tip, dip, pip, mcp));
			}

			std::array<Models::Body::Finger, 5> fingersArray{ fingers.at(0), fingers.at(1), fingers.at(2), fingers.at(3), fingers.at(4) };
			auto efficioHand = Models::Body::Hand(side, fingersArray);
			efficioHand.Source = SensorInformation.Name;
			efficioHand.ID = hand->QueryUniqueId();

			return efficioHand;
		}

		Models::Body::Finger RealSenseSensor::convertToEfficioFinger(Models::Body::BodySide side, Models::Body::FingerType fingerType, PXCHandData::FingerData finger, PXCHandData::JointData tip, PXCHandData::JointData dip, PXCHandData::JointData pip, PXCHandData::JointData mcp)
		{
			bool isExtended = finger.foldedness > 70;

			Models::Body::JointType efficioTipType;
			Models::Body::JointType efficioDIPType;
			Models::Body::JointType efficioPIPType;
			Models::Body::JointType efficioMCPType;

			switch (fingerType)
			{
			case Efficio::Models::Body::FingerType::Unknown:
				break;
			case Efficio::Models::Body::FingerType::Thumb:
				efficioTipType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandThumbTIP : Models::Body::JointType::RightHandThumbTIP;
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandThumbDIP : Models::Body::JointType::RightHandThumbDIP;
				efficioPIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandThumbCMP : Models::Body::JointType::RightHandThumbCMP;
				efficioMCPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandThumbMCP : Models::Body::JointType::RightHandThumbMCP;
				break;
			case Efficio::Models::Body::FingerType::Index:
				efficioTipType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandIndexTIP : Models::Body::JointType::RightHandIndexTIP;
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandIndexDIP : Models::Body::JointType::RightHandIndexDIP;
				efficioPIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandIndexPIP : Models::Body::JointType::RightHandIndexPIP;
				efficioMCPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandIndexMCP : Models::Body::JointType::RightHandIndexMCP;
				break;
			case Efficio::Models::Body::FingerType::Middle:
				efficioTipType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandMiddleTIP : Models::Body::JointType::RightHandMiddleTIP;
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandMiddleDIP : Models::Body::JointType::RightHandMiddleDIP;
				efficioPIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandMiddlePIP : Models::Body::JointType::RightHandMiddlePIP;
				efficioMCPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandMiddleMCP : Models::Body::JointType::RightHandMiddleMCP;
				break;
			case Efficio::Models::Body::FingerType::Ring:
				efficioTipType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandRingTIP : Models::Body::JointType::RightHandRingTIP;
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandRingDIP : Models::Body::JointType::RightHandRingDIP;
				efficioPIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandRingPIP : Models::Body::JointType::RightHandRingPIP;
				efficioMCPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandRingMCP : Models::Body::JointType::RightHandRingMCP;
				break;
			case Efficio::Models::Body::FingerType::Pinky:
				efficioTipType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandPinkyTIP : Models::Body::JointType::RightHandPinkyTIP;
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandPinkyDIP : Models::Body::JointType::RightHandPinkyDIP;
				efficioPIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandPinkyPIP : Models::Body::JointType::RightHandPinkyPIP;
				efficioMCPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandPinkyMCP : Models::Body::JointType::RightHandPinkyMCP;
				break;
			default:
				break;
			}

			Vector3 tipPosition(-tip.positionWorld.x * 1000, tip.positionWorld.y * 1000, tip.positionWorld.z * 1000);
			Vector3 dipPosition(-dip.positionWorld.x * 1000, dip.positionWorld.y * 1000, dip.positionWorld.z * 1000);
			Vector3 pipPosition(-pip.positionWorld.x * 1000, pip.positionWorld.y * 1000, pip.positionWorld.z * 1000);
			Vector3 mcpPosition(-mcp.positionWorld.x * 1000, mcp.positionWorld.y * 1000, mcp.positionWorld.z * 1000);

			float fingerLength = tipPosition.DistanceTo(dipPosition) + dipPosition.DistanceTo(pipPosition) + pipPosition.DistanceTo(mcpPosition);


			Models::Body::Joint efficioTip(tipPosition, efficioTipType);
			Models::Body::Joint efficioDIP(dipPosition, efficioDIPType);
			Models::Body::Joint efficioPIP(pipPosition, efficioPIPType);
			Models::Body::Joint efficioMCP(mcpPosition, efficioMCPType);

			auto efficioFinger = Models::Body::Finger(fingerType, isExtended, fingerLength, efficioTip, efficioDIP, efficioPIP, efficioMCP);

			return efficioFinger;
		}

		Models::Body::HandData RealSenseSensor::GetHandData()
		{
			std::vector<Models::Body::Hand> hands;

			if (handDataOutput->Update() == PXC_STATUS_NO_ERROR)
			{
				PXCHandData::IHand* hand;
				for (int i = 0; i < handDataOutput->QueryNumberOfHands(); ++i)
				{
					handDataOutput->QueryHandData(PXCHandData::AccessOrderType::ACCESS_ORDER_BY_ID, i, hand);
					hands.push_back(convertToEfficioHand(hand));
				}
			}

			return Models::Body::HandData(hands);
		}

		Models::AudioVisual::ImageData RealSenseSensor::GetImageData()
		{
			Models::AudioVisual::ImageData data;

			// retrieve the color and depth samples aligned
			auto *sample = sampleReader->GetSample();
			auto imageInfo = sample->color->QueryInfo();
		




			//Models::AudioVisual::Image(imageInfo.height, imageInfo.width, 8, )

			return data;
		}

		//Models::Body::Face::FaceData RealSenseSensor::GetFaceData()
		//{
		//	Data::Body::Face::FaceData data;

		//	if (faceDataOutput->Update() == PXC_STATUS_NO_ERROR)
		//	{
		//		PXCFaceData::ExpressionsData::FaceExpressionResult result;
		//		for (size_t i = 0; i < faceDataOutput->QueryNumberOfDetectedFaces(); i++)
		//		{
		//			for (int expressionInt = 0; expressionInt != 21; expressionInt++)
		//			{
		//				if (expressionInt < 9 || expressionInt > 14)
		//				{
		//					auto face = faceDataOutput->QueryFaceByIndex(i);
		//					auto expressions = face->QueryExpressions();

		//					if (expressions->QueryExpression(static_cast<PXCFaceData::ExpressionsData::FaceExpression>(expressionInt), &result))
		//					{
		//						Data::Body::Face::Expressions expression;
		//						switch (expressionInt)
		//						{
		//						case 0:
		//						{
		//							expression = Data::Body::Face::Expressions::LeftBrowRaised;
		//							break;
		//						}
		//						case 1:
		//						{
		//							expression = Data::Body::Face::Expressions::RightBrowRaised;
		//							break;
		//						}
		//						case 2:
		//						{
		//							expression = Data::Body::Face::Expressions::LeftBrowLowered;
		//							break;
		//						}
		//						case 3:
		//						{
		//							expression = Data::Body::Face::Expressions::RightBrowLowered;
		//							break;
		//						}
		//						case 4:
		//						{
		//							expression = Data::Body::Face::Expressions::Smiling;
		//							break;
		//						}
		//						case 5:
		//						{
		//							expression = Data::Body::Face::Expressions::Kissing;
		//							break;
		//						}
		//						case 6:
		//						{
		//							expression = Data::Body::Face::Expressions::OpenMouth;
		//							break;
		//						}
		//						case 7:
		//						{
		//							expression = Data::Body::Face::Expressions::LeftEyeClosed;
		//							break;
		//						}
		//						case 8:
		//						{
		//							expression = Data::Body::Face::Expressions::RightEyeClosed;
		//							break;
		//						}
		//						case 15:
		//						{
		//							expression = Data::Body::Face::Expressions::EyesLookingLeft;
		//							break;
		//						}
		//						case 16:
		//						{
		//							expression = Data::Body::Face::Expressions::EyesLookingRight;
		//							break;
		//						}
		//						case 17:
		//						{
		//							expression = Data::Body::Face::Expressions::EyesLookingUp;
		//							break;
		//						}
		//						case 18:
		//						{
		//							expression = Data::Body::Face::Expressions::EyesLookingDown;
		//							break;
		//						}
		//						case 19:
		//						{
		//							expression = Data::Body::Face::Expressions::TongueOut;
		//							break;
		//						}
		//						case 20:
		//						{
		//							expression = Data::Body::Face::Expressions::RightCheekPuffed;
		//							break;
		//						}
		//						case 21:
		//						{
		//							expression = Data::Body::Face::Expressions::LeftCheekPuffed;
		//							break;
		//						}
		//						default:
		//							break;
		//						}

		//						//data.Expressions.emplace(expression, result.intensity);
		//					}
		//				}
		//			}
		//		}
		//	}

		//	return data;
		//}
	}
}