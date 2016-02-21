#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
   
   int x = 1233; 
   int i = 0;
   int a[] = { [9] = x + 1, [2] = 3, [1] = 2, [0] = 1 };
   
   for (; i <= 9; ++i) 
   {
   	NSLog(@"element at %i = %i", i, a[i]);
   }
   
   [pool drain];
}