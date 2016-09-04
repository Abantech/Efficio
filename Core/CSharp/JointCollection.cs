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

public class JointCollection : global::System.IDisposable, global::System.Collections.IEnumerable
    , global::System.Collections.Generic.IEnumerable<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t>
 {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal JointCollection(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(JointCollection obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~JointCollection() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          EfficioPINVOKE.delete_JointCollection(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public JointCollection(global::System.Collections.ICollection c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < size())
        throw new global::System.ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

  public void CopyTo(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t[] array)
  {
    CopyTo(0, array, 0, this.Count);
  }

  public void CopyTo(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t[] array, int arrayIndex)
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

  public void CopyTo(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t[] array, int arrayIndex, int count)
  {
    if (array == null)
      throw new global::System.ArgumentNullException("array");
    if (index < 0)
      throw new global::System.ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new global::System.ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new global::System.ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new global::System.ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new global::System.ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

  global::System.Collections.Generic.IEnumerator<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t> global::System.Collections.Generic.IEnumerable<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t>.GetEnumerator() {
    return new JointCollectionEnumerator(this);
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator() {
    return new JointCollectionEnumerator(this);
  }

  public JointCollectionEnumerator GetEnumerator() {
    return new JointCollectionEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class JointCollectionEnumerator : global::System.Collections.IEnumerator
    , global::System.Collections.Generic.IEnumerator<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t>
  {
    private JointCollection collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public JointCollectionEnumerator(JointCollection collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t Current {
      get {
        if (currentIndex == -1)
          throw new global::System.InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new global::System.InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new global::System.InvalidOperationException("Collection modified.");
        return (SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object global::System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new global::System.InvalidOperationException("Collection modified.");
      }
    }

    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
  }

  public void Clear() {
    EfficioPINVOKE.JointCollection_Clear(swigCPtr);
  }

  public void Add(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t x) {
    EfficioPINVOKE.JointCollection_Add(swigCPtr, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(x));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  private uint size() {
    uint ret = EfficioPINVOKE.JointCollection_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = EfficioPINVOKE.JointCollection_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    EfficioPINVOKE.JointCollection_reserve(swigCPtr, n);
  }

  public JointCollection() : this(EfficioPINVOKE.new_JointCollection__SWIG_0(), true) {
  }

  public JointCollection(JointCollection other) : this(EfficioPINVOKE.new_JointCollection__SWIG_1(JointCollection.getCPtr(other)), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public JointCollection(int capacity) : this(EfficioPINVOKE.new_JointCollection__SWIG_2(capacity), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  private SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t getitemcopy(int index) {
    SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t ret = new SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t(EfficioPINVOKE.JointCollection_getitemcopy(swigCPtr, index), true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t getitem(int index) {
    SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t ret = new SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t(EfficioPINVOKE.JointCollection_getitem(swigCPtr, index), false);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t val) {
    EfficioPINVOKE.JointCollection_setitem(swigCPtr, index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(val));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(JointCollection values) {
    EfficioPINVOKE.JointCollection_AddRange(swigCPtr, JointCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public JointCollection GetRange(int index, int count) {
    global::System.IntPtr cPtr = EfficioPINVOKE.JointCollection_GetRange(swigCPtr, index, count);
    JointCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new JointCollection(cPtr, true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t x) {
    EfficioPINVOKE.JointCollection_Insert(swigCPtr, index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(x));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, JointCollection values) {
    EfficioPINVOKE.JointCollection_InsertRange(swigCPtr, index, JointCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    EfficioPINVOKE.JointCollection_RemoveAt(swigCPtr, index);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    EfficioPINVOKE.JointCollection_RemoveRange(swigCPtr, index, count);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public static JointCollection Repeat(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t value, int count) {
    global::System.IntPtr cPtr = EfficioPINVOKE.JointCollection_Repeat(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Joint_t.getCPtr(value), count);
    JointCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new JointCollection(cPtr, true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    EfficioPINVOKE.JointCollection_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    EfficioPINVOKE.JointCollection_Reverse__SWIG_1(swigCPtr, index, count);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, JointCollection values) {
    EfficioPINVOKE.JointCollection_SetRange(swigCPtr, index, JointCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

}

}