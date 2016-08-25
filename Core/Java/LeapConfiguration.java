/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public class LeapConfiguration {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected LeapConfiguration(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(LeapConfiguration obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        EfficioJNI.delete_LeapConfiguration(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public LeapConfiguration() {
    this(EfficioJNI.new_LeapConfiguration(), true);
  }

  public void setEnabled(boolean value) {
    EfficioJNI.LeapConfiguration_Enabled_set(swigCPtr, this, value);
  }

  public boolean getEnabled() {
    return EfficioJNI.LeapConfiguration_Enabled_get(swigCPtr, this);
  }

}
