/**
* below shows how to organize the C++ program with the separation model
* in this model, we do not include the whole definition of the template in the header file 
* instead, we only place the template declaration in the header file, and we put a explicit 
* definition in some source file, which is decorated with the keyword export 
*/

template <typename Type> Type min2(Type t1, Type t2);