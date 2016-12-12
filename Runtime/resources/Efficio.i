%module EfficioRuntime
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "Gesture.h"
	#include "Vector3.h"
	#include "Joint.h"
	#include "Finger.h"
	#include "BodySide.h"
	#include "Frame.h"
	#include "Engine.h"
	#include "DiscreteGesture.h"
	#include "Pinch.h"
	#include "Hand.h"
	#include "DataType.h"
	#include "EfficioStarted.h"
 %}

 %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>
 %include <std_array.i>
 %include <std_map.i>

 %shared_ptr(Efficio::Frame);
 %shared_ptr(Efficio::Events::Event);
 %shared_ptr(Efficio::Events::Internal::EfficioStarted);
 %shared_ptr(Efficio::InputRecognition::Gesture);
 %shared_ptr(Efficio::InputRecognition::DiscreteGesture);
 %shared_ptr(Efficio::InputRecognition::Body::Hands::Pinch);
 %shared_ptr(Efficio::Data::Data);


 /* Parse the header file to generate wrappers */
 
 %include "Vector3.h"

	 /* Enumerations */
		%include "BodySide.h"
		%include "DataType.h"
		%include "EventType.h"
		%include "SensorStatus.h"
		%include "TrackingType.h"
		%include "JointType.h"
		%include "FingerType.h"
		%include "GestureType.h"
		%include "GestureState.h"
		
 %include "Data.h"
 %include "Joint.h"
 %include "Finger.h"
 %include "Hand.h"
 %include "Event.h" 
 %include "Frame.h"
 %include "Engine.h"
 %include "Gesture.h"
 %include "DiscreteGesture.h"
 %include "Pinch.h"
 %include "EfficioStarted.h"
 
 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Events::Event>>;
 %template(GestureCollection) std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>>;
 %template(DataCollection) std::vector<std::shared_ptr<Efficio::Data::Data>>;
 %template(JointCollection) std::vector<Efficio::Models::Body::Joint>;
 %template(FingerCollection) std::array<Efficio::Models::Body::Finger,5>;