//
// Created by ehud on 29/04/18.
//

#ifndef CPP_6_BOARD_H
#define CPP_6_BOARD_H
using namespace std;
#include <iostream>
#include "Piece.h"
#include "vector"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include "Coordinate.h"
class Board {
public:
    Board(){};
    friend ostream& operator<< (ostream& os, Board& b);
    Board& operator=(const Board& b);
    Board(const Board& b);
    Board& operator=(char c);
    Piece& operator[]( vector<int> v) const;
    Board(int size);
    void init_Board(int dim);
    int size()const;
    void fill(char c);
    ~Board();
private:
    int m_size;
    Piece** m_board;
};


#endif //CPP_6_BOARD_H