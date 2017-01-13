%module EfficioRuntime
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "SensorEvent.h"
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
	#include "SensorInformation.h"
	#include "EfficioStarted.h"
	#include "ButtonPressed.h"
	#include "Connected.h"
	#include "Faulted.h"
	#include "Disconnected.h"
 %}

 %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>
 %include <std_array.i>
 %include <std_map.i>

 %shared_ptr(Efficio::Frame);
 %shared_ptr(Efficio::Events::Event);
 %shared_ptr(Efficio::Sensors::SensorEvent);
 %shared_ptr(Efficio::Events::Internal::EfficioStarted);
 %shared_ptr(Efficio::Sensors::Connected);
 %shared_ptr(Efficio::Sensors::Faulted);
 %shared_ptr(Efficio::Sensors::Disconnected);
 %shared_ptr(Efficio::Sensors::ButtonPressed);
 %shared_ptr(Efficio::InputRecognition::Gesture);
 %shared_ptr(Efficio::InputRecognition::DiscreteGesture);
 %shared_ptr(Efficio::InputRecognition::Body::Hands::Pinch);
 %shared_ptr(Efficio::Data::Data);

 /* Parse the header file to generate wrappers */
 
 %include "Vector3.h"

	 /* Enumerations */
		%include "BodySide.h"
		%include "DataType.h"
		%include "ButtonType.h"
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
 %include "SensorInformation.h"
 %include "SensorEvent.h" 
 %include "Frame.h"
 %include "Engine.h"
 %include "Gesture.h"
 %include "DiscreteGesture.h"
 %include "Pinch.h"
 %include "SensorInformation.h"
 %include "EfficioStarted.h"
 %include "Connected.h"
 %include "Faulted.h"
 %include "Disconnected.h"
 %include "ButtonPressed.h"
 
 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Events::Event>>;
 %template(GestureCollection) std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>>;
 %template(DataCollection) std::vector<std::shared_ptr<Efficio::Data::Data>>;
 %template(JointCollection) std::vector<Efficio::Models::Body::Joint>;
 %template(FingerCollection) std::array<Efficio::Models::Body::Finger,5>;