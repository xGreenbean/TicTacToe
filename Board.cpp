//
// Created by ehud on 29/04/18.
//
#include "Board.h"
/**
 * class builder, initializes a size*size board with '.'.
 * @param s - board dimension
 */


Board::Board(int s) {

    m_size = s;
    m_board = new Piece*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new Piece[m_size];
    }
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

}
void Board::init_Board(int dim) {
    this->m_size=dim;
    m_board = new Piece*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_board[i] = new Piece[m_size];
    }
}
istream& operator>>(istream& is,Board& b){
    for (int i = 0; i <b.size() ; ++i) {
        for (int j = 0; j <b.size() ; ++j) {
            is>>b[{i,j}];
        }
    }
}

ostream& operator<< (ostream& os,const Board& b){
    for (int i = 0; i <b.m_size ; ++i) {
        for (int j = 0; j <b.m_size ; ++j) {
            os<<(b.m_board[i][j].get_p());
        }
        os<<'\n';
    }
    return os;
}
string Board::draw(int n) {
    int dimx = n, dimy = n;
    ofstream imageFile("/home/ehud/Desktop/myimage1", ios::out | ios::binary);
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;

    RGB* matrix=new RGB[n*n];

    whiten(matrix, n);
    for (int l = 0; l <this->size() ; l++) {
        for (int i = 0; i <this->size() ; i++) {
               if(m_board[i][l].get_p()=='X')drawX(l,i,matrix,n);
        }
   }
    imageFile.write(reinterpret_cast<char*>(matrix), n*n*3);
    imageFile.close();
    return "";
}
void Board::drawX(int x1,int y1,RGB* matrix,int n){
    int bound=(((double) n-1)/(double)this->size());
    int thicken=bound*0.05;

    for (int i = (bound*0.10); i <(bound*0.90); ++i) {
        for (int j = 0; j <thicken ; ++j) {
            matrix[n*(i+x1*bound)+(i+(y1*bound))+j].green = 255;
            matrix[n*(i+x1*bound)+(i+(y1*bound))+j].red = 153;
            matrix[n*(i+x1*bound)+(i+(y1*bound))+j].blue = 51;
            matrix[n*((bound)+x1*bound)-n*(i)+(i+(y1*bound))+j].green = 255;
            matrix[n*((bound)+x1*bound)-n*(i)+(i+(y1*bound))+j].red = 153;
            matrix[n*((bound)+x1*bound)-n*(i)+(i+(y1*bound))+j].blue = 51;
        }
    }
}
void Board::whiten(RGB* matrix,int n){
    int bound=(((double) n-1)/(double)this->size());
    int thicken=(bound*0.02);
    for (int i = n*0.02 ; i <n*0.98 ; ++i) {
        for (int j = n*0.02; j <n*0.98 ; ++j) {
            for (int k = 0; k <thicken; ++k) {
                if(i%bound==0||j%bound==0){
                    matrix[(n)*(j+k)+i+k].blue=255;
                    matrix[(n)*(j+k)+i+k].green=255;
                    matrix[(n)*(j+k)+i+k].red=255;
                }
            }

        }
    }
}
