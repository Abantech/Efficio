/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public class EfficioJNI {
  public final static native long new_Vector3(float jarg1, float jarg2, float jarg3);
  public final static native void delete_Vector3(long jarg1);
  public final static native float Vector3_DistanceTo(long jarg1, Vector3 jarg1_, long jarg2, Vector3 jarg2_);
  public final static native float Vector3_X(long jarg1, Vector3 jarg1_);
  public final static native float Vector3_Y(long jarg1, Vector3 jarg1_);
  public final static native float Vector3_Z(long jarg1, Vector3 jarg1_);
  public final static native long new_Joint(int jarg1, long jarg2, Vector3 jarg2_);
  public final static native void delete_Joint(long jarg1);
  public final static native String Joint_GetJointNameString(long jarg1, Joint jarg1_);
  public final static native void Joint_Name_set(long jarg1, Joint jarg1_, int jarg2);
  public final static native int Joint_Name_get(long jarg1, Joint jarg1_);
  public final static native void Joint_Position_set(long jarg1, Joint jarg1_, long jarg2, Vector3 jarg2_);
  public final static native long Joint_Position_get(long jarg1, Joint jarg1_);
  public final static native long new_Finger__SWIG_0();
  public final static native long new_Finger__SWIG_1(int jarg1, long jarg2, JointCollection jarg2_);
  public final static native void delete_Finger(long jarg1);
  public final static native long Finger_GetJointPosition(long jarg1, Finger jarg1_, int jarg2);
  public final static native void Finger_Name_set(long jarg1, Finger jarg1_, int jarg2);
  public final static native int Finger_Name_get(long jarg1, Finger jarg1_);
  public final static native String Finger_GetFingerNameString(long jarg1, Finger jarg1_);
  public final static native String Finger_GetJointNameString(long jarg1, Finger jarg1_, int jarg2);
  public final static native void Finger_Joints_set(long jarg1, Finger jarg1_, long jarg2, JointCollection jarg2_);
  public final static native long Finger_Joints_get(long jarg1, Finger jarg1_);
  public final static native long new_Hand__SWIG_0();
  public final static native long new_Hand__SWIG_1(int jarg1);
  public final static native long new_Hand__SWIG_2(long jarg1, FingerCollection jarg1_, int jarg2);
  public final static native void delete_Hand(long jarg1);
  public final static native long Hand_GetFingers(long jarg1, Hand jarg1_);
  public final static native void Hand_AddFinger(long jarg1, Hand jarg1_, long jarg2);
  public final static native void Hand_Side_set(long jarg1, Hand jarg1_, int jarg2);
  public final static native int Hand_Side_get(long jarg1, Hand jarg1_);
  public final static native void Hand_Fingers_set(long jarg1, Hand jarg1_, long jarg2, FingerCollection jarg2_);
  public final static native long Hand_Fingers_get(long jarg1, Hand jarg1_);
  public final static native void Hand_IsLeftHand_set(long jarg1, Hand jarg1_, boolean jarg2);
  public final static native boolean Hand_IsLeftHand_get(long jarg1, Hand jarg1_);
  public final static native long new_HandData();
  public final static native void delete_HandData(long jarg1);
  public final static native void HandData_Hands_set(long jarg1, HandData jarg1_, long jarg2);
  public final static native long HandData_Hands_get(long jarg1, HandData jarg1_);
  public final static native void delete_Event(long jarg1);
  public final static native int Event_GetEventType(long jarg1, Event jarg1_);
  public final static native long new_Frame();
  public final static native void delete_Frame(long jarg1);
  public final static native void Frame_HandData_set(long jarg1, Frame jarg1_, long jarg2, HandData jarg2_);
  public final static native long Frame_HandData_get(long jarg1, Frame jarg1_);
  public final static native long new_EfficioFrame(int jarg1);
  public final static native void delete_EfficioFrame(long jarg1);
  public final static native long EfficioFrame_GetEvents(long jarg1, EfficioFrame jarg1_);
  public final static native long EfficioFrame_GetHands(long jarg1, EfficioFrame jarg1_);
  public final static native void EfficioFrame_AddEvent(long jarg1, EfficioFrame jarg1_, long jarg2, Event jarg2_);
  public final static native void EfficioFrame_AddHand(long jarg1, EfficioFrame jarg1_, long jarg2);
  public final static native void EfficioFrame_ID_set(long jarg1, EfficioFrame jarg1_, int jarg2);
  public final static native int EfficioFrame_ID_get(long jarg1, EfficioFrame jarg1_);
  public final static native long new_DeviceManager();
  public final static native void delete_DeviceManager(long jarg1);
  public final static native void DeviceManager_AddDevice(long jarg1, DeviceManager jarg1_, long jarg2, Device jarg2_);
  public final static native long DeviceManager_GetDevices(long jarg1, DeviceManager jarg1_);
  public final static native long DeviceManager_GetConnectedDevices(long jarg1, DeviceManager jarg1_);
  public final static native long DeviceManager_GetDevicesWithStatus(long jarg1, DeviceManager jarg1_, int jarg2);
  public final static native long DeviceManager_GetDeviceByID(long jarg1, DeviceManager jarg1_, String jarg2);
  public final static native void DeviceManager_RemoveDevice(long jarg1, DeviceManager jarg1_, String jarg2);
  public final static native long new_Engine();
  public final static native void delete_Engine(long jarg1);
  public final static native void Engine_Start(long jarg1, Engine jarg1_);
  public final static native long Engine_GetFrame__SWIG_0(long jarg1, Engine jarg1_);
  public final static native long Engine_GetFrame__SWIG_1(long jarg1, Engine jarg1_, int jarg2);
  public final static native void Engine_DeviceConfiguration_set(long jarg1, Engine jarg1_, long jarg2, DeviceConfiguration jarg2_);
  public final static native long Engine_DeviceConfiguration_get(long jarg1, Engine jarg1_);
  public final static native void Engine_DeviceManager_set(long jarg1, Engine jarg1_, long jarg2, DeviceManager jarg2_);
  public final static native long Engine_DeviceManager_get(long jarg1, Engine jarg1_);
  public final static native long new_LeapConfiguration();
  public final static native void delete_LeapConfiguration(long jarg1);
  public final static native void LeapConfiguration_Enabled_set(long jarg1, LeapConfiguration jarg1_, boolean jarg2);
  public final static native boolean LeapConfiguration_Enabled_get(long jarg1, LeapConfiguration jarg1_);
  public final static native long new_DeviceConfiguration();
  public final static native void delete_DeviceConfiguration(long jarg1);
  public final static native void DeviceConfiguration_LeapConfiguration_set(long jarg1, DeviceConfiguration jarg1_, long jarg2, LeapConfiguration jarg2_);
  public final static native long DeviceConfiguration_LeapConfiguration_get(long jarg1, DeviceConfiguration jarg1_);
  public final static native void delete_Gesture(long jarg1);
  public final static native int Gesture_GetType(long jarg1, Gesture jarg1_);
  public final static native int Gesture_GetGestureState(long jarg1, Gesture jarg1_);
  public final static native long Gesture_GetStartTime(long jarg1, Gesture jarg1_);
  public final static native long Gesture_GetGestureDuration(long jarg1, Gesture jarg1_);
  public final static native int Gesture_GetEventType(long jarg1, Gesture jarg1_);
  public final static native void delete_DiscreteGesture(long jarg1);
  public final static native int DiscreteGesture_GetType(long jarg1, DiscreteGesture jarg1_);
  public final static native int DiscreteGesture_GetGestureState(long jarg1, DiscreteGesture jarg1_);
  public final static native long new_Pinch(int jarg1, int jarg2, int jarg3, long jarg4, Vector3 jarg4_);
  public final static native void delete_Pinch(long jarg1);
  public final static native void Pinch_Position_set(long jarg1, Pinch jarg1_, long jarg2, Vector3 jarg2_);
  public final static native long Pinch_Position_get(long jarg1, Pinch jarg1_);
  public final static native void Pinch_Finger1_set(long jarg1, Pinch jarg1_, int jarg2);
  public final static native int Pinch_Finger1_get(long jarg1, Pinch jarg1_);
  public final static native void Pinch_Finger2_set(long jarg1, Pinch jarg1_, int jarg2);
  public final static native int Pinch_Finger2_get(long jarg1, Pinch jarg1_);
  public final static native int Pinch_GetEventType(long jarg1, Pinch jarg1_);
  public final static native void Pinch_Side_set(long jarg1, Pinch jarg1_, int jarg2);
  public final static native int Pinch_Side_get(long jarg1, Pinch jarg1_);
  public final static native void delete_Device(long jarg1);
  public final static native void Device_ID_set(long jarg1, Device jarg1_, String jarg2);
  public final static native String Device_ID_get(long jarg1, Device jarg1_);
  public final static native void Device_Position_set(long jarg1, Device jarg1_, long jarg2, Vector3 jarg2_);
  public final static native long Device_Position_get(long jarg1, Device jarg1_);
  public final static native void Device_Direction_set(long jarg1, Device jarg1_, long jarg2, Vector3 jarg2_);
  public final static native long Device_Direction_get(long jarg1, Device jarg1_);
  public final static native void Device_Enabled_set(long jarg1, Device jarg1_, boolean jarg2);
  public final static native boolean Device_Enabled_get(long jarg1, Device jarg1_);
  public final static native boolean Device_Connected(long jarg1, Device jarg1_);
  public final static native int Device_Status(long jarg1, Device jarg1_);
  public final static native int Device_TrackingTypes(long jarg1, Device jarg1_);
  public final static native void Device_Connect(long jarg1, Device jarg1_);
  public final static native void Device_Disconnect(long jarg1, Device jarg1_);
  public final static native boolean Device_HasFrame(long jarg1, Device jarg1_);
  public final static native long Device_GetFrame(long jarg1, Device jarg1_);
  public final static native long new_HandCollection__SWIG_0();
  public final static native long new_HandCollection__SWIG_1(long jarg1);
  public final static native long HandCollection_size(long jarg1, HandCollection jarg1_);
  public final static native long HandCollection_capacity(long jarg1, HandCollection jarg1_);
  public final static native void HandCollection_reserve(long jarg1, HandCollection jarg1_, long jarg2);
  public final static native boolean HandCollection_isEmpty(long jarg1, HandCollection jarg1_);
  public final static native void HandCollection_clear(long jarg1, HandCollection jarg1_);
  public final static native void HandCollection_add(long jarg1, HandCollection jarg1_, long jarg2);
  public final static native long HandCollection_get(long jarg1, HandCollection jarg1_, int jarg2);
  public final static native void HandCollection_set(long jarg1, HandCollection jarg1_, int jarg2, long jarg3);
  public final static native void delete_HandCollection(long jarg1);
  public final static native long new_FingerCollection__SWIG_0();
  public final static native long new_FingerCollection__SWIG_1(long jarg1);
  public final static native long FingerCollection_size(long jarg1, FingerCollection jarg1_);
  public final static native long FingerCollection_capacity(long jarg1, FingerCollection jarg1_);
  public final static native void FingerCollection_reserve(long jarg1, FingerCollection jarg1_, long jarg2);
  public final static native boolean FingerCollection_isEmpty(long jarg1, FingerCollection jarg1_);
  public final static native void FingerCollection_clear(long jarg1, FingerCollection jarg1_);
  public final static native void FingerCollection_add(long jarg1, FingerCollection jarg1_, long jarg2);
  public final static native long FingerCollection_get(long jarg1, FingerCollection jarg1_, int jarg2);
  public final static native void FingerCollection_set(long jarg1, FingerCollection jarg1_, int jarg2, long jarg3);
  public final static native void delete_FingerCollection(long jarg1);
  public final static native long new_JointCollection__SWIG_0();
  public final static native long new_JointCollection__SWIG_1(long jarg1);
  public final static native long JointCollection_size(long jarg1, JointCollection jarg1_);
  public final static native long JointCollection_capacity(long jarg1, JointCollection jarg1_);
  public final static native void JointCollection_reserve(long jarg1, JointCollection jarg1_, long jarg2);
  public final static native boolean JointCollection_isEmpty(long jarg1, JointCollection jarg1_);
  public final static native void JointCollection_clear(long jarg1, JointCollection jarg1_);
  public final static native void JointCollection_add(long jarg1, JointCollection jarg1_, long jarg2);
  public final static native long JointCollection_get(long jarg1, JointCollection jarg1_, int jarg2);
  public final static native void JointCollection_set(long jarg1, JointCollection jarg1_, int jarg2, long jarg3);
  public final static native void delete_JointCollection(long jarg1);
  public final static native long new_EventCollection__SWIG_0();
  public final static native long new_EventCollection__SWIG_1(long jarg1);
  public final static native long EventCollection_size(long jarg1, EventCollection jarg1_);
  public final static native long EventCollection_capacity(long jarg1, EventCollection jarg1_);
  public final static native void EventCollection_reserve(long jarg1, EventCollection jarg1_, long jarg2);
  public final static native boolean EventCollection_isEmpty(long jarg1, EventCollection jarg1_);
  public final static native void EventCollection_clear(long jarg1, EventCollection jarg1_);
  public final static native void EventCollection_add(long jarg1, EventCollection jarg1_, long jarg2, Event jarg2_);
  public final static native long EventCollection_get(long jarg1, EventCollection jarg1_, int jarg2);
  public final static native void EventCollection_set(long jarg1, EventCollection jarg1_, int jarg2, long jarg3, Event jarg3_);
  public final static native void delete_EventCollection(long jarg1);
  public final static native long new_GestureCollection__SWIG_0();
  public final static native long new_GestureCollection__SWIG_1(long jarg1);
  public final static native long GestureCollection_size(long jarg1, GestureCollection jarg1_);
  public final static native long GestureCollection_capacity(long jarg1, GestureCollection jarg1_);
  public final static native void GestureCollection_reserve(long jarg1, GestureCollection jarg1_, long jarg2);
  public final static native boolean GestureCollection_isEmpty(long jarg1, GestureCollection jarg1_);
  public final static native void GestureCollection_clear(long jarg1, GestureCollection jarg1_);
  public final static native void GestureCollection_add(long jarg1, GestureCollection jarg1_, long jarg2, Gesture jarg2_);
  public final static native long GestureCollection_get(long jarg1, GestureCollection jarg1_, int jarg2);
  public final static native void GestureCollection_set(long jarg1, GestureCollection jarg1_, int jarg2, long jarg3, Gesture jarg3_);
  public final static native void delete_GestureCollection(long jarg1);
  public final static native long new_DeviceCollection__SWIG_0();
  public final static native long new_DeviceCollection__SWIG_1(long jarg1);
  public final static native long DeviceCollection_size(long jarg1, DeviceCollection jarg1_);
  public final static native long DeviceCollection_capacity(long jarg1, DeviceCollection jarg1_);
  public final static native void DeviceCollection_reserve(long jarg1, DeviceCollection jarg1_, long jarg2);
  public final static native boolean DeviceCollection_isEmpty(long jarg1, DeviceCollection jarg1_);
  public final static native void DeviceCollection_clear(long jarg1, DeviceCollection jarg1_);
  public final static native void DeviceCollection_add(long jarg1, DeviceCollection jarg1_, long jarg2, Device jarg2_);
  public final static native long DeviceCollection_get(long jarg1, DeviceCollection jarg1_, int jarg2);
  public final static native void DeviceCollection_set(long jarg1, DeviceCollection jarg1_, int jarg2, long jarg3, Device jarg3_);
  public final static native void delete_DeviceCollection(long jarg1);
  public final static native long Gesture_SWIGSmartPtrUpcast(long jarg1);
  public final static native long DiscreteGesture_SWIGSmartPtrUpcast(long jarg1);
  public final static native long Pinch_SWIGSmartPtrUpcast(long jarg1);
}
