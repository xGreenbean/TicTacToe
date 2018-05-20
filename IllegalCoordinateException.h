//
// Created by ehud on 06/05/18.
//

#ifndef CPP_6_ILLEGALCOORDINATEEXCEPTION_H
#define CPP_6_ILLEGALCOORDINATEEXCEPTION_H
using namespace std;
#include <iostream>
#include <string>
#include "vector"

class IllegalCoordinateException {
private:
    int x;
    int y;
public:
    string theCoordinate()const;
    IllegalCoordinateException(int xx,int yy);
};


#endif //CPP_6_ILLEGALCOORDINATEEXCEPTION_H
