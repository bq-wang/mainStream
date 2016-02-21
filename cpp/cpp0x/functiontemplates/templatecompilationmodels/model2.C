#include "model2.h"

/** it seems that the export keywod is not supported in gnu g++ compiler */
/*export*/ template<typename Type>
Type min2(Type t1, Type t2) {
  return t1 < t2 ? t1 : t2;
}
