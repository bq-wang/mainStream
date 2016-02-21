#import <Foundation/Foundation.h>
// Block to calculate the nth triangular number
void (^calculateTriangularNumber) (int) =
	^(int n) {
	int i, triangularNumber = 0;
	for ( i = 1; i <= n; ++i )
	triangularNumber += i;
	NSLog (@"Triangular number %i is %i", n, triangularNumber);
} ;

int main (int argc, char * argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	calculateTriangularNumber (10);
	calculateTriangularNumber (20);
	calculateTriangularNumber (50);
	
	[pool drain];
	return 0;
}