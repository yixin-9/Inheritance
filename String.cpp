//  String.cpp
//  Implementation for the Derived Class: String
//

#include <iostream>
#include <string>
#include "String.h"

namespace CS52 {
   
    String::String():Container(),_size(0),data(nullptr){ //default constructor
        
    }
    
    String::String(const char str[]){  // overloaded constructor String str (" abcd ")
        
        unsigned long temp =strlen(str);
        _size=static_cast<int>(temp)+1; //change unsigned type to int
        data= new char [_size];  //allocate memory
        for(int i=0; i<_size;i++){
            data[i]=str[i];
        }
    }
    
    String::String(const String &b){  // copy Constructor
        _size=b._size;
        data= new char [_size];  //allocate memory
        for (int i=0; i<(_size); i++) {
            data[i]=b.data[i]; //assign b to data
        }
        
    }
    
    String &String::operator=(const String &b){// copy assignment
        if (this==&b) {
            return *this;
        }
        delete [] this->data;  //delete memory
        _size=b._size;
        this->data= new char[_size];  //allocate memory
        for (int i=0; i<_size; i++) {
            this->data[i]=b.data[i];
        }
        return *this;
    }
    
    String::~String(){ // Destructor
        if (data!=nullptr) {
            delete [] data;
            data=nullptr;
        }
    }
    
    std::ostream &operator << (std::ostream &stream, String &iString){  // overloaded ostream << operator
        for (int i=0; i<iString.size(); i++) {
            stream<<iString[i]; 
        }
        return stream;
    }
    
    String String::operator +(String &b){  // Overloaded + operators to perform concatenation
       
        String a;
        a.data=new char[_size+a.length()+1]; //allocate memory; +1 for null character
        strcpy(a.data, data);  //copy data to a.data
        strcat(a.data, b.data);  //conactenates
        
        return a.data;
    }
    
    String String::operator +(char *that){// Overloaded + operators to perform concatenation
        
        String a;
        a.data= new char [_size+strlen(that)+1];
        strcpy(a.data, data);  //copy data to a.data
        strcat(a.data, that);  //concatenates
        
        return a.data;
    }
    
    char &String::operator[] (int i){  // Overloaded [] operator to access element i
        if (i >= _size) throw 1;
        return data[i];
    }
    
    int String::length() const{ //optional length
        return _size-1;  //exclude null character
    }
    
    int String::size() const{  // override Container's size()
        return _size-1;  //exclude null character
    }
    
    std::string String::type() const{  // override Container's type()
        return "CS52::String";
    }

} //CS52
