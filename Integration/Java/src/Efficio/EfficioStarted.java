/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio;

public class EfficioStarted extends InternalEvent {
  private transient long swigCPtr;
  private boolean swigCMemOwnDerived;

  protected EfficioStarted(long cPtr, boolean cMemoryOwn) {
    super(EfficioRuntimeJNI.EfficioStarted_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(EfficioStarted obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        EfficioRuntimeJNI.delete_EfficioStarted(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public EfficioStarted() {
    this(EfficioRuntimeJNI.new_EfficioStarted(), true);
  }

  public EventType GetEventType() {
    return EventType.swigToEnum(EfficioRuntimeJNI.EfficioStarted_GetEventType(swigCPtr, this));
  }

}
