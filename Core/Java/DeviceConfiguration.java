/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Runtime;

public class DeviceConfiguration {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected DeviceConfiguration(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(DeviceConfiguration obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        EfficioRuntimeJNI.delete_DeviceConfiguration(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public DeviceConfiguration() {
    this(EfficioRuntimeJNI.new_DeviceConfiguration(), true);
  }

  public void setLeapConfiguration(LeapConfiguration value) {
    EfficioRuntimeJNI.DeviceConfiguration_LeapConfiguration_set(swigCPtr, this, LeapConfiguration.getCPtr(value), value);
  }

  public LeapConfiguration getLeapConfiguration() {
    long cPtr = EfficioRuntimeJNI.DeviceConfiguration_LeapConfiguration_get(swigCPtr, this);
    return (cPtr == 0) ? null : new LeapConfiguration(cPtr, false);
  }

}
