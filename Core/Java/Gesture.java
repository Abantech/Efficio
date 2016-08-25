/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public class Gesture extends Event {
  private transient long swigCPtr;
  private boolean swigCMemOwnDerived;

  protected Gesture(long cPtr, boolean cMemoryOwn) {
    super(EfficioJNI.Gesture_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Gesture obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        EfficioJNI.delete_Gesture(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GestureType GetType() {
    return GestureType.swigToEnum(EfficioJNI.Gesture_GetType(swigCPtr, this));
  }

  public GestureState GetGestureState() {
    return GestureState.swigToEnum(EfficioJNI.Gesture_GetGestureState(swigCPtr, this));
  }

  public SWIGTYPE_p_std__time_t GetStartTime() {
    return new SWIGTYPE_p_std__time_t(EfficioJNI.Gesture_GetStartTime(swigCPtr, this), true);
  }

  public SWIGTYPE_p_std__time_t GetGestureDuration() {
    return new SWIGTYPE_p_std__time_t(EfficioJNI.Gesture_GetGestureDuration(swigCPtr, this), true);
  }

  public void Eh() {
    EfficioJNI.Gesture_Eh(swigCPtr, this);
  }

}
