// polymorphism_main.m

// as we already know that id type can be used to store object of an y types. 
// the key is Objective-C system always keeps track of the class to which an ojbect belongs. It also lies in the concept of of dynamic 
// typing and dynamic binding - that is , the system makes the decision about the class of hte object , and therefore
// which method to invoke dynamically, at runtime instead of at compile time. 

// A note on the Compile time vs. Runtime Checking. 
/* 

id dataValue = [[Fraction alloc] init];
 ...
[dataValue setReal: 10.0 andImaginary: 2.5];
	These lines do not produce a warning message from the compiler because the compiler
doesn¡¯t know what type of object is stored inside dataValue when processing your
source file (No, the compiler doesn¡¯t see that earlier a Fraction object was stored inside
that variable!).
	No error message is reported until you run the program containing these lines.  you may get the error such as 
	
	
	-[Fraction setReal:andImaginary:]: unrecognized selector sent to instance 0x103f00

*/


#import <Foundation/Foundation.h>
#import "Fraction.h"
#import "Complex.h"

int main (int argc, char * argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	id dataValue;
	
	Fraction *f1 = [[Fraction alloc] init];
	Complex *c1 = [[Complex alloc] init];
	
	[f1 setTo: 2 over: 5];
	[c1 setReal: 10.0 andImaginary: 2.5];
	
	
	// first dataValue gets a fraction 
	dataValue = f1;
	[dataValue print];
	
	// now dataValue gets a complex number 
	dataValue = c1;
	[dataValue print];

	[pool drain];
	
	return 0;
	
}
