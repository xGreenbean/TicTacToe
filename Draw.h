//
// Created by ehud on 29/05/18.
//

#ifndef CPP_6_DRAW_H
#define CPP_6_DRAW_H
#include <iostream>
#include "Piece.h"
#include "vector"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include <fstream>
#include "Board.h"
/**
 * RGB struct for holdiing the RGB pixels
 */
struct RGB {
    uint8_t red, green, blue;
public:
    RGB() {
        red=0;
        blue=0;
        green=0;
    }
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
class Draw {
public:
    void drawX();
    void drawY();
    Draw(int n,Board board,string);
    ~Draw();
    string draw();
    void drawX(int x1,int y1);
    void drawO(int x1,int y1);
    void border();

private:
    string filename;
    RGB* matrix;
    Board board;
    int size;
    //board bounds (length&&height of a panel)
    int bound;

};


#endif //CPP_6_DRAW_H
