/**
* file:
*   virtually_virtual_new.cpp
* description:
*   this shows how you can use the virutal function to do vritually virtua lnew operator. which simuate the use IClonable in C#
*/

#include "stdafx.h"
#include "virtually_virtual_new.h"

void test_virtually_virtual_new()
{
	Query *pq = new NameQuery("Rike");
	// so this is not working as the 
	// Query::clone() returns Qeury
	//NameQuery * pq2 = pq->clone();
	NameQuery *pnq2 = static_cast<NameQuery *> (pq->clone());
	// but why this is needed of the static cast?
	NameQuery *pnq3 = static_cast<NameQuery *>(pnq2->clone());
}


void test_virtually_virtual_new_return_overloaded()
{
	Query *pq = new NameQuery("Rike");
	NameQuery* pnq2 = static_cast<NameQuery *> (pq->clone());
	// there is no need to do the static_cast as you saw before. 
	//
	NameQuery* pnq3 = pnq2->clone();

}


