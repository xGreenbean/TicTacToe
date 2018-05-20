//
// Created by ehud on 19/05/18.
//

#ifndef CPP_6_PLAYER_H
#define CPP_6_PLAYER_H
#include "Board.h"
class Player{
public:
    char myChar;
    virtual const std::string name() const { return "Player"; }
    virtual const std::vector<int> play(const Board& board) { return {0, 0}; }
    char getChar()const;
    void setChar(char c) { myChar=c;}
};
#endif //cCPP_6_PLAYER_H
