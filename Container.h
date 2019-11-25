//  Container.h
//  Interface for the Base Class: Container
//  This is primarily intended to be used as a base class to derive classes for different kinds of conatiners.


#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>

namespace CS52 {
    class Container {
        public:
        virtual int size() const=0;  //virtual function size
        virtual std::string type() const=0;  //virtual function type
        virtual ~Container() {/* empty body */}  //destructor
    };
} //CS52

#endif //CONTAINER_H
