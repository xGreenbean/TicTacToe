//
// Created by ehud on 29/04/18.
//
#include "Board.h"
#include "Draw.h"
#include <math.h>
#include <string.h>
/**
 * class builder, initializes a size*size board with '.'.
 * @param s - board dimension
 */


Board::Board(int s) {
    init_Board(s);
}
/**
 * copy constructor, deep copy.
 * @param b - Board copied
 */
Board::Board(const Board &b) {
   
    m_size=b.m_size;
    m_board=new Piece*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new Piece[m_size];
    }
    for (int i = 0; i <m_size ; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_board[i][j].set_p(b.m_board[i][j].get_p());
        }
    }
}
/**
 * if the char is legal, we fill the entire board with it.
 * @param c the char
 * @return the filledboard.
 * @throws IllegalCharException.
 */
Board& Board::operator=( char c) {
    fill(c);
    return *this;
}
/**
 * assignment,deep copy?
 * @param b
 * @return
 */
Board& Board::operator=(const Board& b) {
    m_size=b.m_size;
    this->m_board=new Piece*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new Piece[m_size];
    }
    for (int i = 0; i <m_size ; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_board[i][j].set_p(b.m_board[i][j].get_p());
        }
    }
    return *this;
}
//TODO: handle exception
void Board::fill( char c){
    if(c=='.'||c=='X'||c=='O'){
        for (int i = 0; i <m_size ; ++i) {
            for (int j = 0; j < m_size; ++j) {
                m_board[i][j]=c;
            }
        }
    }else throw IllegalCharException(c);

}
//TODO: handle exception
Piece& Board::operator[]( vector<int> v) const {
    if(0<=v.at(1)&&v.at(1)<m_size&&0<=v.at(0)&&v.at(0)<m_size) {
        return m_board[v.at(0)][v.at(1)];
    }
    else {
        throw IllegalCoordinateException(v.at(0),v.at(1));
    }
}
int Board::size() const {
    return this->m_size;
}
Board::~Board(){
    for (int i = 0; i <m_size ; ++i) {
            delete[] m_board[i];
    }
    delete [] m_board;

}
void Board::init_Board(int dim) {
    this->m_size=dim;
    m_board = new Piece*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new Piece[m_size];
    }
}
/* took some inspiration from Samuel Bismuth*/
istream& operator>>(istream& is,Board& b){

    string str;
    int dim = 0, raw = 0;
    is >> str;
    dim = str.length();
    b.init_Board(dim);
    while (is)
    {
        for (int j = 0; j < dim; j++)
            b[{raw, j}] = str[j];
        is >> str;
        raw++;
    }
    return is;
}

ostream& operator<< (ostream& os, Board& b){
    for (int i = 0; i <b.m_size ; ++i) {
        for (int j = 0; j <b.m_size ; ++j) {
            os<<(b.m_board[i][j].get_p());
        }
        os<<'\n';
    }
    return os;
}
/*
 * Draws a picture of a board of n*n pixels
 */
string Board::draw(int n) {
    //making a new file every time.
    string filename="Board";
    struct stat buffer;
    string file=filename+".ppm";
    int i=0;
    //check for existing files
    while(stat (file.c_str(), &buffer) == 0){
        file=filename+"_"+to_string(i)+".ppm";
        i++;
    }
    filename=file;

    //use the Draw class to draw the board
    Draw d=Draw(n,*this,file);
    d.draw();
    return filename;
}
