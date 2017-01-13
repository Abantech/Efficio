%module EfficioRuntime
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "SensorEvent.h"
	#include "InternalEvent.h"
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
	#include "Connecting.h"
	#include "Connected.h"
	#include "Faulted.h"
	#include "Disconnecting.h"
	#include "Disconnected.h"
	#include "Asset.h"
 %}

/* Load external dependencies */
%include <ExternalDependencies.i>

/* Inform SWIG of shared pointers */
%include <SharedPointers.i>

/* Parse the header file to generate wrappers */
%include <Enumerations.i>
%include <Events.i>
%include "Vector3.h"
%include "Data.h"
%include "Joint.h"
%include "Finger.h"
%include "Hand.h"
%include "SensorInformation.h"
%include "Frame.h"
%include "Engine.h"
%include "Sensor.h"
%include "Asset.h"

/* Change vectors and arrays into language-native collections */
%include <templates.i> 