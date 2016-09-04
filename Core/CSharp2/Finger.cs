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

public class Finger : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Finger(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Finger obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Finger() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          EfficioPINVOKE.delete_Finger(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public Finger() : this(EfficioPINVOKE.new_Finger__SWIG_0(), true) {
  }

  public Finger(FingerName fingerName, SWIGTYPE_p_std__mapT_std__string_Efficio__Vector3_t jointPositions) : this(EfficioPINVOKE.new_Finger__SWIG_1((int)fingerName, SWIGTYPE_p_std__mapT_std__string_Efficio__Vector3_t.getCPtr(jointPositions)), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public Vector3 GetJointPosition(string jointName) {
    Vector3 ret = new Vector3(EfficioPINVOKE.Finger_GetJointPosition(swigCPtr, jointName), true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public FingerName Name {
    set {
      EfficioPINVOKE.Finger_Name_set(swigCPtr, (int)value);
    } 
    get {
      FingerName ret = (FingerName)EfficioPINVOKE.Finger_Name_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_std__mapT_std__string_Efficio__Models__Human__Bone2_t Bones {
    set {
      EfficioPINVOKE.Finger_Bones_set(swigCPtr, SWIGTYPE_p_std__mapT_std__string_Efficio__Models__Human__Bone2_t.getCPtr(value));
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      SWIGTYPE_p_std__mapT_std__string_Efficio__Models__Human__Bone2_t ret = new SWIGTYPE_p_std__mapT_std__string_Efficio__Models__Human__Bone2_t(EfficioPINVOKE.Finger_Bones_get(swigCPtr), true);
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string HandSide {
    set {
      EfficioPINVOKE.Finger_HandSide_set(swigCPtr, value);
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = EfficioPINVOKE.Finger_HandSide_get(swigCPtr);
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

}

}