#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidInputException : public std::exception {
public:
    virtual const char* what() const throw() ;
};
#endif // EXCEPTION_H

