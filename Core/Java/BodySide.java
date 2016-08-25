/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package Efficio.Java;

public final class BodySide {
  public final static BodySide Right = new BodySide("Right");
  public final static BodySide Left = new BodySide("Left");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static BodySide swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + BodySide.class + " with value " + swigValue);
  }

  private BodySide(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private BodySide(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private BodySide(String swigName, BodySide swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static BodySide[] swigValues = { Right, Left };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

