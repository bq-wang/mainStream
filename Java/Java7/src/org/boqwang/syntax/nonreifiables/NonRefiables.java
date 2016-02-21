package org.boqwang.syntax.nonreifiables;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
check: 

Improved Compiler Warnings and Errors When Using Non-Reifiable Formal Parameters with Varargs Methods: http://docs.oracle.com/javase/7/docs/technotes/guides/language/non-reifiable-varargs.html

*/

public class NonRefiables {
	public static void HeapPollution() {
	    List l = new ArrayList<Number>();
	    List<String> ls = l;       // unchecked warning
	    l.add(0, new Integer(42)); // another unchecked warning
	    String s = ls.get(0);      // ClassCastException is thrown
	}
		
	/*
     	 Variable Arguments Methods and Non-Reifiable Formal Parameters

	 */
  public static class ArrayBuilder { 
	  public static <T> void addToList (List<T> listArg, T... elements) {
		    for (T x : elements) {
		      listArg.add(x);
		    }
		  }

		  public static void faultyMethod(List<String>... l) {
		    Object[] objectArray = l;  // Valid
		    objectArray[0] = Arrays.asList(new Integer(42));
		    String s = l[0].get(0);    // ClassCastException thrown here
		  }
	  
  }
  
  /*
   
   When you compile the code you will probabbly get the following examples as follow. 
  // warning: [varargs] Possible heap pollution from parameterized vararg type T
   
  */

  public static class HeapPolluteExample {
	  public static void main(String[] args) {

		    List<String> stringListA = new ArrayList<String>();
		    List<String> stringListB = new ArrayList<String>();

		    ArrayBuilder.addToList(stringListA, "Seven", "Eight", "Nine");
		    ArrayBuilder.addToList(stringListA, "Ten", "Eleven", "Twelve");
		    List<List<String>> listOfStringLists = new ArrayList<List<String>>();
		    ArrayBuilder.addToList(listOfStringLists, stringListA, stringListB);

		    ArrayBuilder.faultyMethod(Arrays.asList("Hello!"), Arrays.asList("World!"));
		  }
  }
  
  
  /*
     // Suppressing Warnings from Varargs Methods with Non-Reifiable Formal Parameters

The Java compiler generates the following warnings for this example:

addToList:
  At the method's declaration: [unchecked] Possible heap pollution from parameterized vararg type T
  When the method is called: [unchecked] unchecked generic array creation for varargs parameter of type List<String>[]
addToList2: When the method is called (no warning is generated at the method's declaration): [unchecked] unchecked generic array creation for varargs parameter of type List<String>[]
addToList3: No warnings are generated either at the method's declaration or when it is called.

   */
  public static class ArrayBuilder2 {
	  public static <T> void addToList(List<T> listArg, T ... elements) {
		  
	  }
	  
	  @SuppressWarnings({"unchecked", "varargs"}) // is the {} the same as the array initializer or object initializer in Object?
	  public static <T> void addToList2(List<T> listArg, T ... elements) {
		  
	  }
	  
	  @SafeVarargs
	  public static <T> void addToList3(List<T> listArg, T ... elements) {
		  
	  }
  }
}
