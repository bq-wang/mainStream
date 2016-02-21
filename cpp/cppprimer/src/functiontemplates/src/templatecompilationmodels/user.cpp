#include "stdafx.h"
#include "model2.h"

/** it seems it is not support to in VC++ to have the export keyword
**/
/*export*/ template <typename Type>
	Type min2(Type t1, Type t2) { 
    return t1 < t2 ? t1 : t2;
}