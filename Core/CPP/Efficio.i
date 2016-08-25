%module Efficio
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "Vector3.h"
	#include "Frame.h"
	#include "Enumerations.h"
	#include "EfficioFrame.h"
	#include "Engine.h"
	#include "Gesture.h"
	#include "DiscreteGesture.h"
	#include "Pinch.h"
	#include "RightHandThumbAndIndexPinch.h"
 %}

  %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>
 %shared_ptr(Efficio::Event);
 %shared_ptr(Efficio::InputRecognition::Gesture);
 %shared_ptr(Efficio::InputRecognition::DiscreteGesture);
 %shared_ptr(Efficio::InputRecognition::Human::Hand::Pinch);
 %shared_ptr(Efficio::InputRecognition::Human::Hand::RightHandThumbAndIndexPinch);

 /* Parse the header file to generate wrappers */
 %include "Vector3.h"
 %include "Event.h" 
 %include "Enumerations.h"
 %include "Frame.h"
 %include "EfficioFrame.h "
 %include "Engine.h"
 %include "LeapConfiguration.h"
 %include "DeviceConfiguration.h"
 %include "Gesture.h"
 %include "DiscreteGesture.h"
 %include "Pinch.h"
 %include "RightHandThumbAndIndexPinch.h"

 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Event>>;