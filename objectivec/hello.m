#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
   NSLog(@"hello world");
   [pool drain];
}