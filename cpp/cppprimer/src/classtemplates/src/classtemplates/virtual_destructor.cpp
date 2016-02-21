/**
* file :
*   virtual_destructor.cpp
* description:
*   this file shows how to use teh virtual destructor
*/


#include "stdafx.h"
//#include "virtual_destructor.h"


//void demo_virtual_constructor()
//{
//	Query *pq = new NotQuery();
//	// illegal , destructor is protected
//	delete pq;
//}

/**
* As a general rule of thumb, we recommend that the root base clas of a class hierarchy declaring one or more virtual destructors virtual as well.
* However, unlike the base class constructor, the base destructor, in general, should not be made protected.
*/
//void demo_virtual_constructor1()
//{
//	Query1 *pq = new NotQuery1();
//	delete pq;
//}