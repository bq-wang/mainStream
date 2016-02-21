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
	
	/* 

to declare a variable as a weak variable, you can use the __weak modifier. 


also, if you want to define a variable that has the following  

@property (weak, nonatomic) UIView* parentView; 


this weak notation is not support in iOS4 or Mac OS v10.6, in such cases, you can still use the unsafe_unretained (or assign) property attribute or declare your variable to be __unssafe_unretained...
	
	
	 */
	
		__weak Fraction *f1;
		
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