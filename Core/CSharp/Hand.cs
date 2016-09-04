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

public class Hand : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Hand(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Hand obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Hand() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          EfficioPINVOKE.delete_Hand(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public Hand() : this(EfficioPINVOKE.new_Hand__SWIG_0(), true) {
  }

  public Hand(BodySide side) : this(EfficioPINVOKE.new_Hand__SWIG_1((int)side), true) {
  }

  public Hand(FingerCollection fingers, BodySide side) : this(EfficioPINVOKE.new_Hand__SWIG_2(FingerCollection.getCPtr(fingers), (int)side), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public FingerCollection GetFingers() {
    FingerCollection ret = new FingerCollection(EfficioPINVOKE.Hand_GetFingers(swigCPtr), true);
    return ret;
  }

  public void AddFinger(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Finger_t fingerPtr) {
    EfficioPINVOKE.Hand_AddFinger(swigCPtr, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Finger_t.getCPtr(fingerPtr));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public BodySide Side {
    set {
      EfficioPINVOKE.Hand_Side_set(swigCPtr, (int)value);
    } 
    get {
      BodySide ret = (BodySide)EfficioPINVOKE.Hand_Side_get(swigCPtr);
      return ret;
    } 
  }

  public FingerCollection Fingers {
    set {
      EfficioPINVOKE.Hand_Fingers_set(swigCPtr, FingerCollection.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = EfficioPINVOKE.Hand_Fingers_get(swigCPtr);
      FingerCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new FingerCollection(cPtr, false);
      return ret;
    } 
  }

  public bool IsLeftHand {
    set {
      EfficioPINVOKE.Hand_IsLeftHand_set(swigCPtr, value);
    } 
    get {
      bool ret = EfficioPINVOKE.Hand_IsLeftHand_get(swigCPtr);
      return ret;
    } 
  }

}

}
