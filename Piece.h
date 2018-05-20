//
// Created by ehud on 29/04/18.
//

#ifndef CPP_6_PIECE_H
#define CPP_6_PIECE_H
using namespace std;
#include "IllegalCharException.h"

#include <iostream>
class Piece {
public:
    void set_p(char c);
    char get_p()const;
    void operator=(char c);
    Piece();
    Piece(char c);
    friend ostream& operator << (ostream& os, Piece& p);
     operator char() const ;
//    friend char operator=(char c,Piece& p);
private:
    char p;
};


#endif //CPP_6_PIECE_H