#include "RealSense.h"
#include "HandData.h"

namespace Efficio
{
	namespace Sensors
	{
		RealSense::RealSense() : RealSense(TrackingType::Hand)
		{
		}

		RealSense::RealSense(TrackingType trackingType) : status(Status::Uninitialized), trackingType(trackingType)
		{
			sensorInformation.Name = "Intel Realsense";

			session = PXCSession::CreateInstance();
			if (!session)
			{
				status = Status::Faulted;
				return;
			}

			senseManager = session->CreateSenseManager();
			if (!senseManager)
			{
				status = Status::Faulted;
				ReleaseAll();
				return;
			}

			EnableModule();
		}

		RealSense::~RealSense()
		{
		}

		Status RealSense::Status()
		{
			return status;
		}

		TrackingType RealSense::TrackingTypes()
		{
			return trackingType;
		}

		void RealSense::Connect()
		{
			if (status != Status::Faulted)
			{
				if (senseManager->Init() != PXC_STATUS_NO_ERROR)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}

				status = Status::Connected;
			}
		}

		void RealSense::Disconnect()
		{
			senseManager->Close();
		}

		bool RealSense::HasFrame()
		{
			return status == Status::Connected && senseManager->AcquireFrame() == PXC_STATUS_NO_ERROR;
		}

		Frame RealSense::GetFrame()
		{
			// Check if new frame is available. If not, return previously calculated frame
			if (!HasFrame())
			{
				return LastEfficioFrame;
			}

			Efficio::Frame frame;

			std::vector<Efficio::Models::Body::Hand> convertedHands;

			if (handDataOutput->Update() == PXC_STATUS_NO_ERROR)
			{
				PXCHandData::IHand* hand;
				for (int i = 0; i < handDataOutput->QueryNumberOfHands(); ++i)
				{
					handDataOutput->QueryHandData(PXCHandData::AccessOrderType::ACCESS_ORDER_BY_ID, i, hand);
					convertedHands.push_back(convertToEfficioHand(hand));
				}
			}

			std::vector<std::shared_ptr<Efficio::Data::Data>> data;

			std::shared_ptr<Efficio::Data::Data> dataSharedPtr(new Efficio::Data::Body::HandData(convertedHands));

			data.push_back(dataSharedPtr);

			frame.AddData(data);

			LastEfficioFrame = frame;

			senseManager->ReleaseFrame();

			return frame;
		}

		std::string RealSense::GetSource()
		{
			return sensorInformation.Name;
		}

		SensorInformation RealSense::GetSensorInformation()
		{
			return sensorInformation;
		}

		void RealSense::ReleaseAll()
		{
			if (handConfiguration)
			{
				handConfiguration->Release();
				handConfiguration = NULL;
			}

			if (handDataOutput)
			{
				handDataOutput->Release();
				handDataOutput = NULL;
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

		void RealSense::EnableModule()
		{
			switch (trackingType)
			{
			case TrackingType::Unknown:
				break;
			case TrackingType::Hand:
			{
				if (senseManager->EnableHand(0) != PXC_STATUS_NO_ERROR)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}

				handModule = senseManager->QueryHand();
				if (!handModule)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}

				handDataOutput = handModule->CreateOutput();
				if (!handDataOutput)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}

				handConfiguration = handModule->CreateActiveConfiguration();
				if (!handConfiguration)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}

				handConfiguration->SetTrackingMode(PXCHandData::TRACKING_MODE_FULL_HAND);

				break;
			}
			case TrackingType::Eye:
				break;
			case TrackingType::Face:
				if (senseManager->EnableFace() != PXC_STATUS_NO_ERROR)
				{
					status = Status::Faulted;
					ReleaseAll();
					return;
				}
				break;
			case TrackingType::Body:
				break;
			case TrackingType::Brain:
				break;
			case TrackingType::Image:
				break;
			case TrackingType::Audio:
				break;
			case TrackingType::Speech:
				break;
			case TrackingType::Location:
				break;
			case TrackingType::Orientation:
				break;
			case TrackingType::Analogue:
				break;
			default:
				break;
			}
		}

		Models::Body::Hand RealSense::convertToEfficioHand(PXCHandData::IHand* hand)
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
			efficioHand.Source = GetSource();
			return efficioHand;
		}

		Models::Body::Finger RealSense::convertToEfficioFinger(Models::Body::BodySide side, Models::Body::FingerType fingerType, PXCHandData::FingerData finger,  PXCHandData::JointData tip, PXCHandData::JointData dip, PXCHandData::JointData pip, PXCHandData::JointData mcp)
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
				efficioDIPType = side == Models::Body::BodySide::Left ? Models::Body::JointType::LeftHandThumbIP : Models::Body::JointType::RightHandThumbIP;
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

	}
}