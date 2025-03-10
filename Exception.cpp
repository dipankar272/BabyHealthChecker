#include"Exception.h"
#include <iostream>
#include <stdexcept>

using namespace std;

 const char* InvalidInputException::what() const throw() {
    return "Invalid input Entered!! Please Reenter Correct input!!";
}
