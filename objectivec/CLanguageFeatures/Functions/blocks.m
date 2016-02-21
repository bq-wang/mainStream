#import <Foundation/Foundation.h>

/*

an exmaple of the block syntax:


^(void)
{
	NSLog (@"Programming is fun.");
}


NOTE: There is a special __block modifier (that’s two underscore characters that precede the word block) that enables you to modify the value of a variable from inside the block, and you’ll see
shortly how that’s used.


*/

/*

as it is has been said, they are not part of the Standard ANSI C definition and were added to the language by Apple, Inc. Blocks look and act a lot like functions. 

*/
int main(int argc, char *argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
   
	void (^printMessage)(void) = 
	   ^(void) { 
		 NSLog(@"Programing is fun!");
		};
   
   printMessage();
   [pool drain];
}