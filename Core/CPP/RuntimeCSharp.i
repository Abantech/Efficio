%module EfficioRuntime
 %{
	 /* Includes the header in the wrapper code */
	#include <memory>
	#include "Event.h"
	#include "Vector3.h"
	#include "Frame.h"
	#include "Enumerations.h"
	#include "PinchEvent.h"
	#include "EfficioFrame.h"
	#include "Engine.h"
 %}

 %include <windows.i>
 %include <std_shared_ptr.i>
 %include <std_string.i>
 %include <std_vector.i>
 %shared_ptr(Efficio::Event);
 %shared_ptr(Efficio::Body::Hands::PinchEvent);

 /* Parse the header file to generate wrappers */
 %include "Vector3.h"
 %include "Event.h" 
 %include "Enumerations.h"
 %include "Frame.h"
 %include "PinchEvent.h"
 %include "EfficioFrame.h "
 %include "Engine.h"
 %include "LeapConfiguration.h"
 %include "DeviceConfiguration.h"

 %template(EventCollection) std::vector<std::shared_ptr<Efficio::Event>>;