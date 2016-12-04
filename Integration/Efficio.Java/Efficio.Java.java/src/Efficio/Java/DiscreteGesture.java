/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public class DiscreteGesture extends Gesture {
  private transient long swigCPtr;
  private boolean swigCMemOwnDerived;

  protected DiscreteGesture(long cPtr, boolean cMemoryOwn) {
    super(EfficioRuntimeJNI.DiscreteGesture_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(DiscreteGesture obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        EfficioRuntimeJNI.delete_DiscreteGesture(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public GestureType GetType() {
    return GestureType.swigToEnum(EfficioRuntimeJNI.DiscreteGesture_GetType(swigCPtr, this));
  }

  public GestureState GetGestureState() {
    return GestureState.swigToEnum(EfficioRuntimeJNI.DiscreteGesture_GetGestureState(swigCPtr, this));
  }

}
