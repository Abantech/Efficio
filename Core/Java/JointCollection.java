/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public class JointCollection {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected JointCollection(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(JointCollection obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        EfficioJNI.delete_JointCollection(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public JointCollection() {
    this(EfficioJNI.new_JointCollection__SWIG_0(), true);
  }

  public JointCollection(long n) {
    this(EfficioJNI.new_JointCollection__SWIG_1(n), true);
  }

  public long size() {
    return EfficioJNI.JointCollection_size(swigCPtr, this);
  }

  public long capacity() {
    return EfficioJNI.JointCollection_capacity(swigCPtr, this);
  }

  public void reserve(long n) {
    EfficioJNI.JointCollection_reserve(swigCPtr, this, n);
  }

  public boolean isEmpty() {
    return EfficioJNI.JointCollection_isEmpty(swigCPtr, this);
  }

  public void clear() {
    EfficioJNI.JointCollection_clear(swigCPtr, this);
  }

  public void add(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t x) {
    EfficioJNI.JointCollection_add(swigCPtr, this, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(x));
  }

  public SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t get(int i) {
    return new SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t(EfficioJNI.JointCollection_get(swigCPtr, this, i), false);
  }

  public void set(int i, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t val) {
    EfficioJNI.JointCollection_set(swigCPtr, this, i, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(val));
  }

}