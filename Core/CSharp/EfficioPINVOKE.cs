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

class EfficioPINVOKE {

  protected class SWIGExceptionHelper {

    public delegate void ExceptionDelegate(string message);
    public delegate void ExceptionArgumentDelegate(string message, string paramName);

    static ExceptionDelegate applicationDelegate = new ExceptionDelegate(SetPendingApplicationException);
    static ExceptionDelegate arithmeticDelegate = new ExceptionDelegate(SetPendingArithmeticException);
    static ExceptionDelegate divideByZeroDelegate = new ExceptionDelegate(SetPendingDivideByZeroException);
    static ExceptionDelegate indexOutOfRangeDelegate = new ExceptionDelegate(SetPendingIndexOutOfRangeException);
    static ExceptionDelegate invalidCastDelegate = new ExceptionDelegate(SetPendingInvalidCastException);
    static ExceptionDelegate invalidOperationDelegate = new ExceptionDelegate(SetPendingInvalidOperationException);
    static ExceptionDelegate ioDelegate = new ExceptionDelegate(SetPendingIOException);
    static ExceptionDelegate nullReferenceDelegate = new ExceptionDelegate(SetPendingNullReferenceException);
    static ExceptionDelegate outOfMemoryDelegate = new ExceptionDelegate(SetPendingOutOfMemoryException);
    static ExceptionDelegate overflowDelegate = new ExceptionDelegate(SetPendingOverflowException);
    static ExceptionDelegate systemDelegate = new ExceptionDelegate(SetPendingSystemException);

    static ExceptionArgumentDelegate argumentDelegate = new ExceptionArgumentDelegate(SetPendingArgumentException);
    static ExceptionArgumentDelegate argumentNullDelegate = new ExceptionArgumentDelegate(SetPendingArgumentNullException);
    static ExceptionArgumentDelegate argumentOutOfRangeDelegate = new ExceptionArgumentDelegate(SetPendingArgumentOutOfRangeException);

    [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="SWIGRegisterExceptionCallbacks_Efficio")]
    public static extern void SWIGRegisterExceptionCallbacks_Efficio(
                                ExceptionDelegate applicationDelegate,
                                ExceptionDelegate arithmeticDelegate,
                                ExceptionDelegate divideByZeroDelegate, 
                                ExceptionDelegate indexOutOfRangeDelegate, 
                                ExceptionDelegate invalidCastDelegate,
                                ExceptionDelegate invalidOperationDelegate,
                                ExceptionDelegate ioDelegate,
                                ExceptionDelegate nullReferenceDelegate,
                                ExceptionDelegate outOfMemoryDelegate, 
                                ExceptionDelegate overflowDelegate, 
                                ExceptionDelegate systemExceptionDelegate);

    [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="SWIGRegisterExceptionArgumentCallbacks_Efficio")]
    public static extern void SWIGRegisterExceptionCallbacksArgument_Efficio(
                                ExceptionArgumentDelegate argumentDelegate,
                                ExceptionArgumentDelegate argumentNullDelegate,
                                ExceptionArgumentDelegate argumentOutOfRangeDelegate);

    static void SetPendingApplicationException(string message) {
      SWIGPendingException.Set(new global::System.ApplicationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArithmeticException(string message) {
      SWIGPendingException.Set(new global::System.ArithmeticException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingDivideByZeroException(string message) {
      SWIGPendingException.Set(new global::System.DivideByZeroException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIndexOutOfRangeException(string message) {
      SWIGPendingException.Set(new global::System.IndexOutOfRangeException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidCastException(string message) {
      SWIGPendingException.Set(new global::System.InvalidCastException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidOperationException(string message) {
      SWIGPendingException.Set(new global::System.InvalidOperationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIOException(string message) {
      SWIGPendingException.Set(new global::System.IO.IOException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingNullReferenceException(string message) {
      SWIGPendingException.Set(new global::System.NullReferenceException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOutOfMemoryException(string message) {
      SWIGPendingException.Set(new global::System.OutOfMemoryException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOverflowException(string message) {
      SWIGPendingException.Set(new global::System.OverflowException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingSystemException(string message) {
      SWIGPendingException.Set(new global::System.SystemException(message, SWIGPendingException.Retrieve()));
    }

    static void SetPendingArgumentException(string message, string paramName) {
      SWIGPendingException.Set(new global::System.ArgumentException(message, paramName, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArgumentNullException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentNullException(paramName, message));
    }
    static void SetPendingArgumentOutOfRangeException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentOutOfRangeException(paramName, message));
    }

    static SWIGExceptionHelper() {
      SWIGRegisterExceptionCallbacks_Efficio(
                                applicationDelegate,
                                arithmeticDelegate,
                                divideByZeroDelegate,
                                indexOutOfRangeDelegate,
                                invalidCastDelegate,
                                invalidOperationDelegate,
                                ioDelegate,
                                nullReferenceDelegate,
                                outOfMemoryDelegate,
                                overflowDelegate,
                                systemDelegate);

      SWIGRegisterExceptionCallbacksArgument_Efficio(
                                argumentDelegate,
                                argumentNullDelegate,
                                argumentOutOfRangeDelegate);
    }
  }

  protected static SWIGExceptionHelper swigExceptionHelper = new SWIGExceptionHelper();

  public class SWIGPendingException {
    [global::System.ThreadStatic]
    private static global::System.Exception pendingException = null;
    private static int numExceptionsPending = 0;

    public static bool Pending {
      get {
        bool pending = false;
        if (numExceptionsPending > 0)
          if (pendingException != null)
            pending = true;
        return pending;
      } 
    }

    public static void Set(global::System.Exception e) {
      if (pendingException != null)
        throw new global::System.ApplicationException("FATAL: An earlier pending exception from unmanaged code was missed and thus not thrown (" + pendingException.ToString() + ")", e);
      pendingException = e;
      lock(typeof(EfficioPINVOKE)) {
        numExceptionsPending++;
      }
    }

    public static global::System.Exception Retrieve() {
      global::System.Exception e = null;
      if (numExceptionsPending > 0) {
        if (pendingException != null) {
          e = pendingException;
          pendingException = null;
          lock(typeof(EfficioPINVOKE)) {
            numExceptionsPending--;
          }
        }
      }
      return e;
    }
  }


  protected class SWIGStringHelper {

    public delegate string SWIGStringDelegate(string message);
    static SWIGStringDelegate stringDelegate = new SWIGStringDelegate(CreateString);

    [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="SWIGRegisterStringCallback_Efficio")]
    public static extern void SWIGRegisterStringCallback_Efficio(SWIGStringDelegate stringDelegate);

    static string CreateString(string cString) {
      return cString;
    }

    static SWIGStringHelper() {
      SWIGRegisterStringCallback_Efficio(stringDelegate);
    }
  }

  static protected SWIGStringHelper swigStringHelper = new SWIGStringHelper();


  static EfficioPINVOKE() {
  }


  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_Vector3___")]
  public static extern global::System.IntPtr new_Vector3(float jarg1, float jarg2, float jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Vector3___")]
  public static extern void delete_Vector3(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Vector3_X___")]
  public static extern float Vector3_X(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Vector3_Y___")]
  public static extern float Vector3_Y(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Vector3_Z___")]
  public static extern float Vector3_Z(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Event___")]
  public static extern void delete_Event(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Event_GetEventType___")]
  public static extern int Event_GetEventType(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_Frame___")]
  public static extern global::System.IntPtr new_Frame();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Frame___")]
  public static extern void delete_Frame(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EfficioFrame_ID_set___")]
  public static extern void EfficioFrame_ID_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EfficioFrame_ID_get___")]
  public static extern int EfficioFrame_ID_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_EfficioFrame___")]
  public static extern global::System.IntPtr new_EfficioFrame(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_EfficioFrame___")]
  public static extern void delete_EfficioFrame(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EfficioFrame_GetEvents___")]
  public static extern global::System.IntPtr EfficioFrame_GetEvents(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EfficioFrame_AddEvent___")]
  public static extern void EfficioFrame_AddEvent(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_Engine___")]
  public static extern global::System.IntPtr new_Engine();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Engine___")]
  public static extern void delete_Engine(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Engine_Start___")]
  public static extern void Engine_Start(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Engine_GetFrame__SWIG_0___")]
  public static extern global::System.IntPtr Engine_GetFrame__SWIG_0(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Engine_GetFrame__SWIG_1___")]
  public static extern global::System.IntPtr Engine_GetFrame__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Engine_DeviceConfiguration_set___")]
  public static extern void Engine_DeviceConfiguration_set(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Engine_DeviceConfiguration_get___")]
  public static extern global::System.IntPtr Engine_DeviceConfiguration_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_LeapConfiguration___")]
  public static extern global::System.IntPtr new_LeapConfiguration();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_LeapConfiguration___")]
  public static extern void delete_LeapConfiguration(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_LeapConfiguration_Enabled_set___")]
  public static extern void LeapConfiguration_Enabled_set(global::System.Runtime.InteropServices.HandleRef jarg1, bool jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_LeapConfiguration_Enabled_get___")]
  public static extern bool LeapConfiguration_Enabled_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_DeviceConfiguration___")]
  public static extern global::System.IntPtr new_DeviceConfiguration();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_DeviceConfiguration___")]
  public static extern void delete_DeviceConfiguration(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_DeviceConfiguration_LeapConfiguration_set___")]
  public static extern void DeviceConfiguration_LeapConfiguration_set(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_DeviceConfiguration_LeapConfiguration_get___")]
  public static extern global::System.IntPtr DeviceConfiguration_LeapConfiguration_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Gesture___")]
  public static extern void delete_Gesture(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_GetType___")]
  public static extern int Gesture_GetType(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_GetGestureState___")]
  public static extern int Gesture_GetGestureState(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_GetStartTime___")]
  public static extern global::System.IntPtr Gesture_GetStartTime(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_GetGestureDuration___")]
  public static extern global::System.IntPtr Gesture_GetGestureDuration(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_GetEventType___")]
  public static extern int Gesture_GetEventType(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_DiscreteGesture___")]
  public static extern void delete_DiscreteGesture(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_DiscreteGesture_GetType___")]
  public static extern int DiscreteGesture_GetType(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_DiscreteGesture_GetGestureState___")]
  public static extern int DiscreteGesture_GetGestureState(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_Pinch___")]
  public static extern global::System.IntPtr new_Pinch(int jarg1, int jarg2, int jarg3, global::System.Runtime.InteropServices.HandleRef jarg4);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_Pinch___")]
  public static extern void delete_Pinch(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Position_set___")]
  public static extern void Pinch_Position_set(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Position_get___")]
  public static extern global::System.IntPtr Pinch_Position_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Finger1_set___")]
  public static extern void Pinch_Finger1_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Finger1_get___")]
  public static extern int Pinch_Finger1_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Finger2_set___")]
  public static extern void Pinch_Finger2_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Finger2_get___")]
  public static extern int Pinch_Finger2_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_GetEventType___")]
  public static extern int Pinch_GetEventType(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Side_set___")]
  public static extern void Pinch_Side_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_Side_get___")]
  public static extern int Pinch_Side_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Clear___")]
  public static extern void EventCollection_Clear(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Add___")]
  public static extern void EventCollection_Add(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_size___")]
  public static extern uint EventCollection_size(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_capacity___")]
  public static extern uint EventCollection_capacity(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_reserve___")]
  public static extern void EventCollection_reserve(global::System.Runtime.InteropServices.HandleRef jarg1, uint jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_EventCollection__SWIG_0___")]
  public static extern global::System.IntPtr new_EventCollection__SWIG_0();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_EventCollection__SWIG_1___")]
  public static extern global::System.IntPtr new_EventCollection__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_EventCollection__SWIG_2___")]
  public static extern global::System.IntPtr new_EventCollection__SWIG_2(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_getitemcopy___")]
  public static extern global::System.IntPtr EventCollection_getitemcopy(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_getitem___")]
  public static extern global::System.IntPtr EventCollection_getitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_setitem___")]
  public static extern void EventCollection_setitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_AddRange___")]
  public static extern void EventCollection_AddRange(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_GetRange___")]
  public static extern global::System.IntPtr EventCollection_GetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Insert___")]
  public static extern void EventCollection_Insert(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_InsertRange___")]
  public static extern void EventCollection_InsertRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_RemoveAt___")]
  public static extern void EventCollection_RemoveAt(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_RemoveRange___")]
  public static extern void EventCollection_RemoveRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Repeat___")]
  public static extern global::System.IntPtr EventCollection_Repeat(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Reverse__SWIG_0___")]
  public static extern void EventCollection_Reverse__SWIG_0(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_Reverse__SWIG_1___")]
  public static extern void EventCollection_Reverse__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EventCollection_SetRange___")]
  public static extern void EventCollection_SetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_EventCollection___")]
  public static extern void delete_EventCollection(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Clear___")]
  public static extern void GestureCollection_Clear(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Add___")]
  public static extern void GestureCollection_Add(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_size___")]
  public static extern uint GestureCollection_size(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_capacity___")]
  public static extern uint GestureCollection_capacity(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_reserve___")]
  public static extern void GestureCollection_reserve(global::System.Runtime.InteropServices.HandleRef jarg1, uint jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_GestureCollection__SWIG_0___")]
  public static extern global::System.IntPtr new_GestureCollection__SWIG_0();

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_GestureCollection__SWIG_1___")]
  public static extern global::System.IntPtr new_GestureCollection__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_new_GestureCollection__SWIG_2___")]
  public static extern global::System.IntPtr new_GestureCollection__SWIG_2(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_getitemcopy___")]
  public static extern global::System.IntPtr GestureCollection_getitemcopy(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_getitem___")]
  public static extern global::System.IntPtr GestureCollection_getitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_setitem___")]
  public static extern void GestureCollection_setitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_AddRange___")]
  public static extern void GestureCollection_AddRange(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_GetRange___")]
  public static extern global::System.IntPtr GestureCollection_GetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Insert___")]
  public static extern void GestureCollection_Insert(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_InsertRange___")]
  public static extern void GestureCollection_InsertRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_RemoveAt___")]
  public static extern void GestureCollection_RemoveAt(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_RemoveRange___")]
  public static extern void GestureCollection_RemoveRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Repeat___")]
  public static extern global::System.IntPtr GestureCollection_Repeat(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Reverse__SWIG_0___")]
  public static extern void GestureCollection_Reverse__SWIG_0(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_Reverse__SWIG_1___")]
  public static extern void GestureCollection_Reverse__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_GestureCollection_SetRange___")]
  public static extern void GestureCollection_SetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_delete_GestureCollection___")]
  public static extern void delete_GestureCollection(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_EfficioFrame_SWIGSmartPtrUpcast___")]
  public static extern global::System.IntPtr EfficioFrame_SWIGSmartPtrUpcast(global::System.IntPtr jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Gesture_SWIGSmartPtrUpcast___")]
  public static extern global::System.IntPtr Gesture_SWIGSmartPtrUpcast(global::System.IntPtr jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_DiscreteGesture_SWIGSmartPtrUpcast___")]
  public static extern global::System.IntPtr DiscreteGesture_SWIGSmartPtrUpcast(global::System.IntPtr jarg1);

  [global::System.Runtime.InteropServices.DllImport("Efficio", EntryPoint="CSharp_EfficiofNet_Pinch_SWIGSmartPtrUpcast___")]
  public static extern global::System.IntPtr Pinch_SWIGSmartPtrUpcast(global::System.IntPtr jarg1);
}

}