/**
* file:
*  typeid_operator.cpp
* description:
* the code below hows how to use the typeid operator 
*/

class employee 
{
};
class manager : public employee
{};

class programmer : public employee 
{
};
/** 
* what is the typeid operator used for? 
* 
* it is used in advanced programming developement, when building debugger for example, or it is used to deal with persistent object through a pointer or a reference to a base class.
* 
* the program needs to find out the actual type of the object manipulated to list the properties of an object properly during a debugging session or to store and retrieve an object property 
* during a debugging session or to store and retrieve an object property properly to find out the actual type of an object, the typeid operator can be used. 
*/


