/*

this does not contains any valid code, but instead it contains some illustrative code that shows how the internally manages the structures within the 

Q:

How can you create a typedef that has the same name as the strucutre types, such as the definition as below is workable?


struct A
{

};

typedef struct A A;

is a valid definition?


*/ 

/* Points. */


struct CGPoint 
{

	CGFloat x;
	CFFloat y;
};


typedef struct CGPoint CGPoint;


/* Sizes */

struct CGSize
{
	CGFloat width;
	CGFloat height;
};

typedef struct CGSize CGSize;

struct CGRect {
CGPoint origin;
CGSize size;
} ;
typedef struct CGRect CGRect;
