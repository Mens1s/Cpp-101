#include <iostream>
using namespace std;

int main(){
    /*
        Q1-
            a-) What is the slicing problem in C++? Does Java have a slicing problem?
                
                Answer)
                    When a derived class object is assigned to a base class object in C++, the derived class object's extra attributes are sliced off
                to generate the base class object; and this whole process termed object slicing.
                    
                    For example:
                        class A {
                            int foo;
                            };

                            class B : public A {
                            int bar;
                        };

                        B b;

                        A a = b;

                        Then the information in b about member bar is lost in a.
                    
                    In java, you cannot change the runtime type of an object. You would need to construct a new object of the superclass runtime type. But however, slicing problem 
                occurs java too.
            
            b-) What are the differences between move constructors and copy constructors?

                Answer)
                    With move constructor, new object or assigned object takes parameter or variable reference (same location) of base class but with copy constructor new object or
                assigned object takes values of variables of base class, it copies the values. 
                    With copy constructor we need a 2x memory location but any changes in the derived class does not effect to base class. 
                
                    Move constructor moves the resources in the heap, i.e., unlike copy constructors which copy the data of the existing object and assigning it to the new object 
                    move constructor just makes the pointer of the declared object to point to the data of temporary object and nulls out the pointer of the temporary objects.
                    Thus, move constructor prevents unnecessarily copying data in the memory.  
    */

    return 0;
}