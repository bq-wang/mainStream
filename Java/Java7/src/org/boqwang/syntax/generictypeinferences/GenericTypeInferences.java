package org.boqwang.syntax.generictypeinferences;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
check: 

Type Inference for Generic Instance Creation: http://docs.oracle.com/javase/7/docs/technotes/guides/language/type-inference-generic-instance-creation.html
 
 */
public class GenericTypeInferences {

	public static void main(String[] args) {
		// Prior
		Map<String, List<String>> myMap = new HashMap<String, List<String>>();
		
		// in Java SE 7
		Map<String, List<String>> myMap2 = new HashMap<>();
		
		// do not do this, because this means a raw type HashMap, not the Map<String, List<String>> type is created 
		// NOTE: There wouls be a unchecked exception
		Map<String, List<String>> myMap3 = new HashMap();
		
		List<String> list = new ArrayList<>();
		list.add("A");
		
		// the following statement should fail since addAll expects 
		// collection<? extends String>
		/* list.addAll(new ArrayList<>()); */
		
		// As an admonition, often use the Diamond primarily for variable declaration
		List<? extends String> list2 = new ArrayList<>();
		list.addAll(list2);
		
		
		// Test on the type inference on Generic constructor
		MyClass<Integer> myClass1 = new MyClass<Integer>(""); // class MyClass<X = Integer>
		                                                      //  <T = String> MyClass <T = String t) { ... }
		
		// it can also infer the type parameter of the generic constructors 
		MyClass<Integer> myObject2 = new MyClass<>("");

	}
	
	/* 
	 Type Inference  and Generic Constructors of Generic and Non-Generic Classes
  
      Note that constructors can be generic (in other words, declare their own formal type parameters) in both generic and non-generic classes. Consider the following example:
	 
	 */
	static 
	class MyClass<X> {
		  <T> MyClass(T t) {
		    // ...
		  }
	}
}
