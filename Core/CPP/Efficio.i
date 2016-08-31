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
    #include "SingleHandGestureDetector.h"
    #include "PinchDetector.h"
 %}

  %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>

 /* Parse the header file to generate wrappers */
 %include "Vector3.h"
 %include "EventType.h"
 %include "Event.h" 
 %include "Enumerations.h"
 %include "Frame.h"
 %include "EfficioFrame.h "
 %include "Engine.h"
 %include "LeapConfiguration.h"
 %include "DeviceConfiguration.h"
 %include "SingleHandGestureDetector.h"
 %include "PinchDetector.h"
 %include "Gesture.h"
 %include "DiscreteGesture.h"
 %include "SingleHandGesture.h"
 %include "Pinch.h"

 %shared_ptr(Efficio::Events::Event);
 %shared_ptr(Efficio::InputRecognition::Gesture);
 %shared_ptr(Efficio::InputRecognition::DiscreteGesture);
 %shared_ptr(Efficio::InputRecognition::Human::Hand::Pinch);
 
 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Events::Event>>;
 %template(GestureCollection) std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>>;