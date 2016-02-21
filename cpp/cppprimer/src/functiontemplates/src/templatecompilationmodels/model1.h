/**
* below shows how to organize the C++ program with the inclusion model
* where we include the definition of the function termplate in every file in which the tempalte is instantiated
* normally that is achieve by putting the template definition in the a header file , and include the header file 
* the .C file which instantiate the template 
*/

template <typename Type>
Type min(Type t1, Type t2) 
{
  return t1 < t2 ? t1 : t2;	
}
