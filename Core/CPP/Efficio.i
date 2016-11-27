%module Efficio
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "Vector3.h"
	#include "Frame.h"
	#include "Enumerations.h"
	#include "Engine.h"
	#include "Gesture.h"
	#include "DiscreteGesture.h"
	#include "Pinch.h"
	#include "Joint.h"
	#include "Vector3.h"
 %}

 %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>

 %shared_ptr(Efficio::Frame);
 %shared_ptr(Efficio::EfficioFrame);

 %shared_ptr(Efficio::Events::Event);
 %shared_ptr(Efficio::InputRecognition::Gesture);
 %shared_ptr(Efficio::InputRecognition::DiscreteGesture);
 %shared_ptr(Efficio::InputRecognition::Human::Hands::Pinch);
 %shared_ptr(Efficio::Device);

 /* Parse the header file to generate wrappers */
 
 %include "Vector3.h"

	 /* Enumerations */
		%include "Enumerations.h"
		%include "Joint.h"
		%include "EventType.h"
		%include "DeviceStatus.h"
		%include "TrackingType.h"

		
 %include "Finger.h"
 %include "Hand.h"
 %include "Event.h" 
 %include "Frame.h"
 %include "DeviceManager.h"
 %include "Engine.h"
 %include "LeapConfiguration.h"
 %include "DeviceConfiguration.h"
 %include "Gesture.h"
 %include "DiscreteGesture.h"
 %include "Pinch.h"
 %include "Device.h"
 
 %template(HandCollection) std::vector<std::shared_ptr<Efficio::Models::Human::Hand>>;
 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Events::Event>>;
 %template(GestureCollection) std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>>;
 %template(DeviceCollection) std::vector<std::shared_ptr<Efficio::Device>>;