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

public class HandCollection : global::System.IDisposable, global::System.Collections.IEnumerable
    , global::System.Collections.Generic.IEnumerable<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t>
 {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal HandCollection(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(HandCollection obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~HandCollection() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          EfficioPINVOKE.delete_HandCollection(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public HandCollection(global::System.Collections.ICollection c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t element in c) {
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

  public SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t this[int index]  {
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

  public void CopyTo(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t[] array)
  {
    CopyTo(0, array, 0, this.Count);
  }

  public void CopyTo(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t[] array, int arrayIndex)
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

  public void CopyTo(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t[] array, int arrayIndex, int count)
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

  global::System.Collections.Generic.IEnumerator<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t> global::System.Collections.Generic.IEnumerable<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t>.GetEnumerator() {
    return new HandCollectionEnumerator(this);
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator() {
    return new HandCollectionEnumerator(this);
  }

  public HandCollectionEnumerator GetEnumerator() {
    return new HandCollectionEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class HandCollectionEnumerator : global::System.Collections.IEnumerator
    , global::System.Collections.Generic.IEnumerator<SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t>
  {
    private HandCollection collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public HandCollectionEnumerator(HandCollection collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t Current {
      get {
        if (currentIndex == -1)
          throw new global::System.InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new global::System.InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new global::System.InvalidOperationException("Collection modified.");
        return (SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t)currentObject;
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
    EfficioPINVOKE.HandCollection_Clear(swigCPtr);
  }

  public void Add(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t x) {
    EfficioPINVOKE.HandCollection_Add(swigCPtr, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t.getCPtr(x));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  private uint size() {
    uint ret = EfficioPINVOKE.HandCollection_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = EfficioPINVOKE.HandCollection_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    EfficioPINVOKE.HandCollection_reserve(swigCPtr, n);
  }

  public HandCollection() : this(EfficioPINVOKE.new_HandCollection__SWIG_0(), true) {
  }

  public HandCollection(HandCollection other) : this(EfficioPINVOKE.new_HandCollection__SWIG_1(HandCollection.getCPtr(other)), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public HandCollection(int capacity) : this(EfficioPINVOKE.new_HandCollection__SWIG_2(capacity), true) {
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  private SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t getitemcopy(int index) {
    SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t ret = new SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t(EfficioPINVOKE.HandCollection_getitemcopy(swigCPtr, index), true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t getitem(int index) {
    SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t ret = new SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t(EfficioPINVOKE.HandCollection_getitem(swigCPtr, index), false);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t val) {
    EfficioPINVOKE.HandCollection_setitem(swigCPtr, index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t.getCPtr(val));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(HandCollection values) {
    EfficioPINVOKE.HandCollection_AddRange(swigCPtr, HandCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public HandCollection GetRange(int index, int count) {
    global::System.IntPtr cPtr = EfficioPINVOKE.HandCollection_GetRange(swigCPtr, index, count);
    HandCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new HandCollection(cPtr, true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t x) {
    EfficioPINVOKE.HandCollection_Insert(swigCPtr, index, SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t.getCPtr(x));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, HandCollection values) {
    EfficioPINVOKE.HandCollection_InsertRange(swigCPtr, index, HandCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    EfficioPINVOKE.HandCollection_RemoveAt(swigCPtr, index);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    EfficioPINVOKE.HandCollection_RemoveRange(swigCPtr, index, count);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public static HandCollection Repeat(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t value, int count) {
    global::System.IntPtr cPtr = EfficioPINVOKE.HandCollection_Repeat(SWIGTYPE_p_std__shared_ptrT_Efficio__Models__Human__Hand_t.getCPtr(value), count);
    HandCollection ret = (cPtr == global::System.IntPtr.Zero) ? null : new HandCollection(cPtr, true);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    EfficioPINVOKE.HandCollection_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    EfficioPINVOKE.HandCollection_Reverse__SWIG_1(swigCPtr, index, count);
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, HandCollection values) {
    EfficioPINVOKE.HandCollection_SetRange(swigCPtr, index, HandCollection.getCPtr(values));
    if (EfficioPINVOKE.SWIGPendingException.Pending) throw EfficioPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
