// conversion_main.m

/*

Conversion rules:  

The Objective-C compiler adheres to very strict rules when it comes to evaluating expressions that consist of different basic data types.

The following summarizes the order in which conversions take place in the evaluation of two operands in an expression:
	1. If either operand is of type long double, the other is converted to long double, and that is the type of the result.
	2. If either operand is of type double, the other is converted to double, and that is the type of the result.
	3. If either operand is of type float, the other is converted to float, and that is the type of the result.
	4. If either operand is of type _Bool, char, short int, or bit field,1 or of an enumerated data type, it is converted to int.
	5. If either operand is of type long long int, the other is converted to long long int, and that is the type of the result.
	6. If either operand is of type long int, the other is converted to long int, and that is the type of the result.
	7. If this step is reached, both operands are of type int, and that is the type of the result.
	
*/