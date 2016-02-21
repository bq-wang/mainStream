// mutable_immutable.m


/*

in this file, we will discuss the immutable and mutable strings, the immutable strings are strings that the contents cannot be changed afer it has been constructed

while the mutable strings are strings whose contents can be dynamically grows and that you can freeze or create a immutable strings out of the mutable ones. 

*/

#import <Foundation/Foundation.h>
int main(int argc, const char *argv[])
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSString *str1 = @"This is string A";
	NSString *str2 = @"THis is string B";
	NSString *res;
	
	// the comparison result denote the relationship between two strings, unlike most other C implementation
	// where you can use negative, 0, positive numbers to denote the relative relationship
	NSComparisonResult compareResult;
	
	// Count the number of Characters
	NSLog(@"Length of str1: %lu", [str1 length]);
	
	// Copy one string to another
	res = [NSString stringWithString: str1];
	NSLog (@"copy: %@", res);
	
	// Copy one string to the end of another
	str2 = [str1 stringByAppendingString: str2];
	NSLog (@"Concatentation: %@", str2);
	
	// Test if 2 strings are equal
	if ([str1 isEqualToString: res] == YES) 
		NSLog(@"str1 == res");
	else 
		NSLog(@"str1 != res");
	
		// Test if one string is <, == or > than another
	compareResult = [str1 compare: str2];
	if (compareResult == NSOrderedAscending)
		NSLog (@"str1 < str2");
	else if (compareResult == NSOrderedSame)
		NSLog (@"str1 == str2");
	else // must be NSOrderedDescending
		NSLog (@"str1 > str2");
	
	// Convert a string to uppercase
	res = [str1 uppercaseString];
	NSLog(@"Uppercase conversion: %s", [res UTF8String]);
	
	// Convert a string to lowercase
	res = [str1 lowercaseString];
	NSLog(@"lowercase conversion:%@", res);
	
	NSLog(@"Original string: %@", str1);
	
	/* 
	
	Instead of most of the C implementation which choose to return two integer to denote the range, Objective-C does 
	
	has a range class that helps you to get the range in a more general and more objective-oriented way.
	
	*/
	
	
	NSRange subRange; 
	// Basic String operations - Continued 
	// Extract first 3 chars from string
	res = [str1 substringToIndex: 3];
	NSLog (@"First 3 chars of str1: %@", res);
	
	// Extract chars to end of string starting at index 5
	res = [str1 substringFromIndex: 5];
	NSLog (@"Chars from index 5 of str1: %@", res);
	
	// Extract chars from index 8 through 13 (6 chars)
	res = [[str1 substringFromIndex: 8] substringToIndex: 6];
	NSLog (@"Chars from index 8 through 13: %@", res);
	
	// An easier way to do the same thing
	res = [str1 substringWithRange: NSMakeRange (8, 6)];
	NSLog (@"Chars from index 8 through 13: %@", res);
	
	// Locate one string inside another
	subRange = [str1 rangeOfString: @"string A"];
	NSLog (@"String is at index %lu, length is %lu",
		subRange.location, subRange.length);
	
	subRange = [str1 rangeOfString: @"string B"];
	if (subRange.location == NSNotFound)
		NSLog (@"String not found");
	else
		NSLog (@"String is at index %lu, length is %lu",
	subRange.location, subRange.length);
	
	
	
	[pool drain];
}
