//  Vector.cpp
//  Implementation for the Derived Class: Vector
//

#include <iostream>
#include <exception>
#include <vector>
#include <string>

#include "Vector.h"

namespace CS52 {
    
    Vector::Vector():Container(), iSize(0), iCapacity(0), iData(nullptr){ //default constructor
     
    }
    
    Vector::Vector(int s,int iVal){  //overloaded constructor
        
        if (s==0) { //if s equal 0, do nothing
            ;
        }
        else{
            iData=new int[s]; //else allocate new memory
            for (int i=0; i<s; i++) {
                iData[i]=iVal;
                iCapacity++;
            }
        }
        iSize=s;
    }
    
   Vector::Vector(const Vector &b){  //copy constructor
        iSize=b.iSize;
        iData= new int[iSize];  //allocate memory
        for (int i=0; i<iSize; i++) {
            iData[i]=b.iData[i];  //assign b to iData
        }
    }
    
    Vector::~Vector(){  //destructor
        if (iData!=nullptr) {
            delete [] iData;
            iData=nullptr;
        }
    }
    
    int& Vector::at(int i) const throw (std::out_of_range) {  // Set element at location i in Vector
        if (i>=iSize) {  //if i greater or equal to iSize, print out-of-bounds and throw
            std::cout<<"out-of-bounds ";
            throw std::out_of_range("at");
        }
        else
            return iData[i];  //else return the vector
    }
    
    int& Vector::back()const throw(std::out_of_range){
        try{
            return iData[iSize-1];  //return the last element of the vector
        }
        catch(std::exception e){
            throw e;
        }
    }
    
    int Vector::capacity() const{
        return iCapacity;  //return capacity
    }
    
    void Vector::clear(){
        iSize=0; //clear the Vector, size equals to 0
    }
    
    int* Vector::data() const{
        return iData;  //return pointer to the first element in the vector .
    }
    
    bool Vector::empty() const{
        if (iSize==0) {  //if vector is empty return true
            return 1;
        }
        else
            return 0;
    }
    
    int& Vector::front()const throw(std::out_of_range){
        try{
            return iData[0];  //return the first element of the vector
        }
        catch(std::exception e){
            throw e;
        }
    }
    
    void Vector::pop_back(){
        iSize=iSize-1; //remove the last element
    }
    
    void Vector::push_back(int element){
        if (iSize+1>iCapacity) { //if the iSize+1 is greater than the iCapacity
            if (iCapacity==0) {  //if iCapacity=0, assign iCapacity to 1
                iCapacity=1;
            }
            iCapacity=iCapacity*2;
            int* tmp= new int[iCapacity];  //allocate memory
            for (int i=0; i<iSize; i++) { //assign iData to temporary memory
                tmp[i]=iData[i];
            }
            delete [] iData;  //delete memory
            iData=tmp;  //assign back to iData
        }
        iData[iSize]= element;  //add element to the end of the vector
        iSize++;  //iSize increase 1
    }
    
    int Vector::size() const{
        return iSize;  //return the number of container elements
    }
    
    std::string Vector::type() const{
        return "CS52::Vector";
    }
    
    void Vector::sort(){ //selection sort
        for (int i=0; i<iSize-1; i++) {
            int minIndex= i;
            for (int j=i+1; j<iSize; j++) {
                if (iData[j]<iData[minIndex]) {  //if iData[j] is greater than the previous iData
                    minIndex=j;  //assign j to minIndex
                }
            }
            //swap to arrange the vector in ascending order
            int temp= iData[minIndex];
            iData[minIndex]=iData[i];
            iData[i]=temp;
        }
    }
    
    
    int& Vector::operator[](int i){  //overloaded operator // array syntax
        return iData[i];
    }
    
    Vector & Vector::operator=(const Vector &b){  //copy assignment
        if (this == &b)
        {
            return *this;
        }
        delete[] this->iData;  //delete memory
        iSize= b.iSize;
        this->iData = new int[iCapacity];  //allocate new memory
        for(int i=0; i<iCapacity; i++)
        {
            this->iData[i] = b.iData[i];
        }
        return *this;
    }
    
    //friend operator, overloaded stream insertion operator
    std::ostream & operator<<(std::ostream& stream, Vector& iVector){
        for (int i = 0; i<iVector.size(); i++)
        {
            stream << iVector.at(i)<<" ";
        }
        return stream;
    }
    
    void Vector::Vector::copy_data(){
        int *a=iData;  //store the original data in pointer a
        iData= new int[iCapacity*2];  //allocate memory
        
        for (int i=0; i<iCapacity; i++) {  //initialize the new memory with pointer a
            iData[i]=a[i];
        }
        iCapacity=iCapacity*2;  //capacity become twice larger
        delete [] a;  //delete a
    }

} //CS52
