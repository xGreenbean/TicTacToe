//
// Created by ehud on 06/05/18.
//

#ifndef CPP_6_ILLEGALCHAREXCEPTION_H
#define CPP_6_ILLEGALCHAREXCEPTION_H
using namespace std;
#include <iostream>
#include <string>
#include "vector"

class IllegalCharException {
private:
    char ch;
public:
     IllegalCharException(char c);
    char theChar()const;
};


#endif //CPP_6_ILLEGALCHAREXCEPTION_H
