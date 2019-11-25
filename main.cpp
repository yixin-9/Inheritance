// Description : Inheritance- Container will be the base class while Vector and String will be the derived class, the children of Container. We separate the implementation from our interface by creating Vector.h, Vector.cpp, String.h, String.cpp,Container.h and an main.cpp as a driver.

#include <iostream>
#include "Vector.h"
#include "String.h"

using namespace CS52;

int main()
{
    CS52::String str1 ("12345"); // Overloaded constructor
    CS52::String str2 ; // Default constructor
    
    str2= str1 ; // overloaded = copy assignment
    str2[0]='0'; // overloaded [] operator

    CS52::String str3(str2); // Copy constructor
    str3[2]='8';
    std::cout << "CS52::String Testing \n\n";
    std::cout << "str1.length()= " << str1.length() << "\n";
    std::cout << "str1= " << str1 << "\n";
    std::cout << "str2= " << str2 << "\n";
    std::cout << "str3= " << str3 << "\n";
    
    CS52::String a("abc");
    CS52::String b("def");
    CS52::String c= a + b; // copy constructor and concatenation
    CS52::String d; // default constructor
    d = a + "Ya"; // copy assignment and concatenation
    std::cout << "\na= "<<a<<"\t\t"
              << "b= "<<b<<"\n";
    std::cout << "c= "<<c<<"\t"
              << "d= "<<d<<"\n";
    
    // Create an array of container pointers
    CS52::Container *container [2];
    container[0] = new CS52::String("abc"); // assign a String object
    container[1] = new CS52::Vector(5,3); // assign a Vector object
    
    // Print out the type and length of each Container element
    std::cout << "\ntest polymorphism \n";
    for (int i = 0; i < 2; i++) {
        std::cout << "Container [" << i << "]" << " is a " << container[i]->type();
        std::cout << " with length " << container[i]->size() << "\n";
    }
    
    // delete String and Vector Objects Pointed to by Container
    for (int i=0; i<2; i++)
        delete container[i];
   
    return 0;
}
