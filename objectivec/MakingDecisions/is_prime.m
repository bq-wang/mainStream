// is_prime.m

#import <Foundation/Foundation.h>

/*
int main(
int argc, const char *argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	int p, d, isPrime; // there is no bool value in the objective-C programs, so that if you set a value of 1 will trueify the value and the set the value of the 0 will falsify it. 
	
	for (p = 2; p <= 50; ++p) {
		isPrime = 1;
		
		for (d = 2; d < p; ++d) { 
			if (p % d == 0) 
				isPrime = 0;
		}
		
		if (isPrime != 0) 
			NSLog(@"%i ", p);
	}
	
	[pool drain];
}

*/

int main(
int argc, const char *argv[])
{

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	int p, d;
	BOOL isPrime; // objective-C has this BOOL value which has possible value of NO (0) or YES, and no other? the YES or NO value are built-in values.  
	
	for (p = 2; p <= 50; ++p) {
		isPrime = YES;
		
		for (d = 2; d < p; ++d) { 
			if (p % d == 0) 
				isPrime = NO;
				
		}
		
		// isPrime = 2; // actually you can do something with the YES or NO, because you can asssign some value like 2 to the BOOL value, but you are not encouraged to do so . 
		if (isPrime != 0) 
			NSLog(@"%i ", p);
	}
	
	[pool drain];
}








