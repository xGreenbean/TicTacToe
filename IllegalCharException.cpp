//
// Created by ehud on 06/05/18.
//

#include "IllegalCharException.h"
/**
 * Class builder
 * @param c  the Illegal char.
 */
IllegalCharException::IllegalCharException(char c) {
    this->ch=c;
}
/**
 * used for printing purposes.
 * @return the illegal char.
 */
char IllegalCharException::theChar()const {
    return this->ch;
}