/* Events */

/* Base Classes */
%include "Event.h" 
%include "InternalEvent.h" 
%include "SensorEvent.h" 

	/* Gestures */
	%include "Gesture.h"
	%include "DiscreteGesture.h"
	%include "Pinch.h"
	
	/* Internal Events */
	%include "EfficioStarted.h"
	
	/* Sensor Events */
	%include "Connecting.h"
	%include "Connected.h"
	%include "Faulted.h"
	%include "Disconnecting.h"
	%include "Disconnected.h"
	%include "ButtonPressed.h"