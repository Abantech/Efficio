//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.10
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Efficio.Net {

public class Gesture : Event {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  private bool swigCMemOwnDerived;

  internal Gesture(global::System.IntPtr cPtr, bool cMemoryOwn) : base(EfficioRuntimePINVOKE.Gesture_SWIGSmartPtrUpcast(cPtr), true) {
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Gesture obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Gesture() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwnDerived) {
          swigCMemOwnDerived = false;
          EfficioRuntimePINVOKE.delete_Gesture(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public virtual GestureType GetGestureType() {
    GestureType ret = (GestureType)EfficioRuntimePINVOKE.Gesture_GetGestureType(swigCPtr);
    if (EfficioRuntimePINVOKE.SWIGPendingException.Pending) throw EfficioRuntimePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual GestureState GetGestureState() {
    GestureState ret = (GestureState)EfficioRuntimePINVOKE.Gesture_GetGestureState(swigCPtr);
    if (EfficioRuntimePINVOKE.SWIGPendingException.Pending) throw EfficioRuntimePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_std__time_t GetStartTime() {
    SWIGTYPE_p_std__time_t ret = new SWIGTYPE_p_std__time_t(EfficioRuntimePINVOKE.Gesture_GetStartTime(swigCPtr), true);
    if (EfficioRuntimePINVOKE.SWIGPendingException.Pending) throw EfficioRuntimePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_std__time_t GetGestureDuration() {
    SWIGTYPE_p_std__time_t ret = new SWIGTYPE_p_std__time_t(EfficioRuntimePINVOKE.Gesture_GetGestureDuration(swigCPtr), true);
    if (EfficioRuntimePINVOKE.SWIGPendingException.Pending) throw EfficioRuntimePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public override EventType GetEventType() {
    EventType ret = (EventType)EfficioRuntimePINVOKE.Gesture_GetEventType(swigCPtr);
    if (EfficioRuntimePINVOKE.SWIGPendingException.Pending) throw EfficioRuntimePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
