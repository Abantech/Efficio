/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio;

public class Event {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected Event(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Event obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        EfficioRuntimeJNI.delete_Event(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setTime(SWIGTYPE_p_time_t value) {
    EfficioRuntimeJNI.Event_Time_set(swigCPtr, this, SWIGTYPE_p_time_t.getCPtr(value));
  }

  public SWIGTYPE_p_time_t getTime() {
    return new SWIGTYPE_p_time_t(EfficioRuntimeJNI.Event_Time_get(swigCPtr, this), true);
  }

  public void setID(long value) {
    EfficioRuntimeJNI.Event_ID_set(swigCPtr, this, value);
  }

  public long getID() {
    return EfficioRuntimeJNI.Event_ID_get(swigCPtr, this);
  }

  public EventType GetEventType() {
    return EventType.swigToEnum(EfficioRuntimeJNI.Event_GetEventType(swigCPtr, this));
  }

}