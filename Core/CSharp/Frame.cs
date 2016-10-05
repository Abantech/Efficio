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

public class Frame : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  private bool swigCMemOwnBase;

  internal Frame(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwnBase = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Frame obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Frame() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwnBase) {
          swigCMemOwnBase = false;
          EfficioPINVOKE.delete_Frame(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public Frame() : this(EfficioPINVOKE.new_Frame(), true) {
  }

  public HandData HandData {
    set {
      EfficioPINVOKE.Frame_HandData_set(swigCPtr, HandData.getCPtr(value));
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = EfficioPINVOKE.Frame_HandData_get(swigCPtr);
      HandData ret = (cPtr == global::System.IntPtr.Zero) ? null : new HandData(cPtr, false);
      if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_Efficio__Data__Datum GetData(SWIGTYPE_p_Efficio__Data__DatumType dataType) {
    global::System.IntPtr cPtr = EfficioPINVOKE.Frame_GetData(swigCPtr, SWIGTYPE_p_Efficio__Data__DatumType.getCPtr(dataType));
    SWIGTYPE_p_Efficio__Data__Datum ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_Efficio__Data__Datum(cPtr, false);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void AddData(SWIGTYPE_p_Efficio__Data__Datum datum) {
    EfficioPINVOKE.Frame_AddData(swigCPtr, SWIGTYPE_p_Efficio__Data__Datum.getCPtr(datum));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
