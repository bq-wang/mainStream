// strongvar_eg.m



#import <Foundation/Foundation.h>
#import "Fraction.h"
/*

what is happening underneath is actually like this: 


[f1 retain]; // retain the new value 
[f2 release]; // release the old value 
f2 = f1; // copy the reference

*/ 

int main(int argc, char * argv[])
{

	@autoreleasepool { 
	
	/* though it is not necessary to explicitly declare a variable to be a strong variables, you can if you choose to */
	
		__strong Fraction *f1;
		
		f1 = [[Fraction alloc] init];
		
		/*
		Fraction *f1 = [[Fraction alloc] init];
		*/
		Fraction *f2 = [[Fraction alloc] init];
		
		
		[f1 setTo: 1 over: 2];
		[f2 setTo: 1 over: 3];
		
		f2 = f1;
	}
	return 0;
}