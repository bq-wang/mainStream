// typedef_main.m

/*

The following typedef defines a type named NumberObject to be a Number object:
	typedef NSNumber *NumberObject;
Variables subsequently declared to be of type NumberObject, as in
	NumberObject myValue1, myValue2, myResult;
	
are treated as if they were declared in the normal way in your program:
	NSNumber *myValue1, *myValue2, *myResult;
	
To define a new type name with typedef, follow this procedure:
	1. Write the statement as if a variable of the desired type were being declared.
	2. Where the name of the declared variable would normally appear, substitute the new type name.
	3. In front of everything, place the keyword typedef.

*/

