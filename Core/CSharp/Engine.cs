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

public class Engine : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Engine(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Engine obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Engine() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          EfficioPINVOKE.delete_Engine(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public Engine() : this(EfficioPINVOKE.new_Engine(), true) {
  }

  public void Start() {
    EfficioPINVOKE.Engine_Start(swigCPtr);
  }

  public EfficioFrame GetFrame() {
    global::System.IntPtr cPtr = EfficioPINVOKE.Engine_GetFrame__SWIG_0(swigCPtr);
    EfficioFrame ret = (cPtr == global::System.IntPtr.Zero) ? null : new EfficioFrame(cPtr, true);
    return ret;
  }

  public EfficioFrame GetFrame(int count) {
    global::System.IntPtr cPtr = EfficioPINVOKE.Engine_GetFrame__SWIG_1(swigCPtr, count);
    EfficioFrame ret = (cPtr == global::System.IntPtr.Zero) ? null : new EfficioFrame(cPtr, true);
    return ret;
  }

  public DeviceConfiguration DeviceConfiguration {
    set {
      EfficioPINVOKE.Engine_DeviceConfiguration_set(swigCPtr, DeviceConfiguration.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = EfficioPINVOKE.Engine_DeviceConfiguration_get(swigCPtr);
      DeviceConfiguration ret = (cPtr == global::System.IntPtr.Zero) ? null : new DeviceConfiguration(cPtr, false);
      return ret;
    } 
  }

  public DeviceManager DeviceManager {
    set {
      EfficioPINVOKE.Engine_DeviceManager_set(swigCPtr, DeviceManager.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = EfficioPINVOKE.Engine_DeviceManager_get(swigCPtr);
      DeviceManager ret = (cPtr == global::System.IntPtr.Zero) ? null : new DeviceManager(cPtr, false);
      return ret;
    } 
  }

}

}
