//
// Created by ehud on 29/04/18.
//
#include "Piece.h"
/**
 * class builder, default case is for empty board.
 */
Piece::Piece() {
    set_p('.');
}
/**
 * the non default case, p will be set with the char value (if legal).
 * @param c
 */
Piece::Piece( char  c) {
    set_p(c);
}
/**
 * just assigning c to p, if legal.
 * @param c
 */
void Piece::operator=(const char c) {
    set_p(c);
}
/**
 * getter
 * @return p
 */
char Piece::get_p()const {
    return  p;
}

ostream& operator<<(ostream &os, Piece &p) {
    return os<<p.get_p();
}
/**
 * sets p to c, throws exception if char is illegal.
 * @throws IllegalCharException
 * @param c
 */
void Piece::set_p(  char c) {
    if(c=='.'||c=='O'||c=='X'){
        p=c;
    }else throw  IllegalCharException(c);
}
 Piece::operator char() const{
    return get_p();
}

