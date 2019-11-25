//  String.h
//  Interface for the Derived Class: String
//

#ifndef STRING_H
#define STRING_H
#include <string>
#include "Container.h"

namespace CS52 {
    
    class String:public Container
    {
    public:
        // default constructor initialize to empty string
        String();
        
        // overloaded constructor String str (" abcd ");
        String(const char str[]);
       
        // copy Constructor
        String(const String &b);
        
        // copy assignment
        String &operator=(const String &b);
        
        // Destructor
        ~String();
        
        // overloaded ostream << operator
        friend std::ostream &operator << (std::ostream &stream, String &iString);
        
        // Overloaded + operators to perform concatenation
        String operator +(String &b);
        String operator +(char *that);
        
        // Overloaded [] operator to access element i
        char &operator[] (int i);
        
        int length() const; // optional length
        int size() const; // override Container's size()
        std::string type() const; // override Container's type()
       
        // private member variables are as follows :
        private :
        int _size=0; // aka length
        char *data=nullptr; // pointer to null terminated string
    };
} //CS52

#endif /* STRING_H */
