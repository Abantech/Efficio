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

public class DiscreteGesture : Gesture {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  private bool swigCMemOwnDerived;

  internal DiscreteGesture(global::System.IntPtr cPtr, bool cMemoryOwn) : base(EfficioPINVOKE.DiscreteGesture_SWIGSmartPtrUpcast(cPtr), true) {
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(DiscreteGesture obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~DiscreteGesture() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwnDerived) {
          swigCMemOwnDerived = false;
          EfficioPINVOKE.delete_DiscreteGesture(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public override GestureType GetType() {
    GestureType ret = (GestureType)EfficioPINVOKE.DiscreteGesture_GetType(swigCPtr);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public override GestureState GetGestureState() {
    GestureState ret = (GestureState)EfficioPINVOKE.DiscreteGesture_GetGestureState(swigCPtr);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
