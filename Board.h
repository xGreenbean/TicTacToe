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
#include <fstream>
typedef std::vector<int> Coordinate;
struct RGB {
    uint8_t red, green, blue;
public:
    RGB() {
        red=255;
        blue=255;
        green=255;
    }
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
class Board {
public:
    Board(){};
    friend ostream& operator<< (ostream& os,const  Board& b);
    friend istream &operator>>(istream&,Board& b);
    Board& operator=(const Board& b);
    Board(const Board& b);
    Board& operator=(char c);
    Piece& operator[]( vector<int> v) const;
    Board(int size);
    void init_Board(int dim);
    int size()const;
    void fill(char c);
    ~Board();
    string draw(int n);
    void drawX(int x1,int y1,RGB* matrix,int n);
    void whiten(RGB* matrix,int n);
        private:
    int m_size;
    Piece** m_board;
};


#endif //CPP_6_BOARD_H