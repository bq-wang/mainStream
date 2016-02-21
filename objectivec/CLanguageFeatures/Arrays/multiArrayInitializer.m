#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
   NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
   
   int x = 1233; 
   int i = 0;
   int a[] = { [9] = x + 1, [2] = 3, [1] = 2, [0] = 1 };
   
   int M[4][5] = {
			{ 10, 5, -3, 17, 82 } ,
			{ 9, 0, 0, 8, -7 } ,
			{ 32, 20, 1, 0, 14 } ,
			{ 0, 0, 8, 7, 6 }
			} ;
   
   int M2[4][5] = { 10, 5, -3, 17, 82, 9, 0, 0, 8, -7, 32,
	20, 1, 0, 14, 0, 0, 8, 7, 6 } ;

   [pool drain];
}