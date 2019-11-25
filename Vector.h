//  Vector.h
//  Interface for the Derived Class: Vector
//

#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include "Container.h"


namespace CS52 {
    class Vector : public Container
    {
        public :
        
        // Constructors
        Vector(); // default constructor
        Vector(int s, int iVal); // overloaded constructor
        Vector(const Vector &b); // copy constructor
        
        // Destructor
        ~Vector();
        
        // Get or set element at location i in Vector .
        int& at(int i) const throw (std::out_of_range);
        
        // Returns a reference to the last element in the Vector
        int& back() const throw (std::out_of_range);
        
        // Returns the allocated storage for the Vector .
        int capacity() const;
        
        // Erases the elements of the Vector but does not change capacity .
        void clear();
        
        // Returns pointer to the first element in the Vector .
        int* data() const;
        
        // If Vector is empty return true , else false .
        bool empty() const;
        
        // Returns a reference to the first element in a vector .
        int& front() const throw (std::out_of_range);
        
        // Deletes the element at the end of the vector .
        void pop_back();
        
        // Add an element to the end of the vector .
        void push_back(int element);
        
        // Returns the number of container elements .
        int size() const;  // override Container's size()
        
        //Returns CS52::Vector
        std::string type() const; // override Container's type()
        
        // Implementing an integer by selection sort
        void sort();
        
        // Overloaded operators
        int& operator[] (int i); // [] array syntax
        Vector & operator =(const Vector &b); // copy assignment
        
        // Overloaded stream insertion operator
        friend std::ostream & operator <<(std::ostream &stream, Vector& iVector);
        
        
        private :
        // helper to copy Vector to new Vector
        void copy_data();
        
        int iSize = 0;
        int iCapacity = 0;
        int * iData = nullptr;
    };
} //CS52

#endif //VECTOR_H
