//
// Created by ehud on 29/05/18.
//

#include "Draw.h"
#include <math.h>

Draw::Draw(int n, Board board,string filename) {
    this->size=n;
    this->board=board;
    this->bound=(((double) n-1)/(double)board.size());
    this->matrix=new RGB[n*n];
    this->filename=filename;
}
Draw::~Draw(){
    delete [] matrix;
}
string Draw::draw() {
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << size <<" " << size << endl << 255 << endl;

    Draw::border();

    for (int l = 0; l <board.size() ; l++) {
        for (int i = 0; i <board.size() ; i++) {
            if(board[{i,l}].get_p()=='X')drawX(l,i);
            if(board[{i,l}].get_p()=='O')drawO(l,i);
        }
    }
    imageFile.write(reinterpret_cast<char*>(matrix), size*size*3);
    imageFile.close();
    return "";
}
void Draw::drawX(int x1,int y1){
    int thicken=bound*0.05;
    for (int i = (bound*0.10); i <(bound*0.90); ++i) {
        for (int j = 0; j <thicken ; ++j) {
            matrix[size*(i+x1*bound)+(i+(y1*bound))+j].green = 153;
            matrix[size*(i+x1*bound)+(i+(y1*bound))+j].red = 51;
            matrix[size*(i+x1*bound)+(i+(y1*bound))+j].blue = 255;
            matrix[size*((bound)+x1*bound)-size*(i)+(i+(y1*bound))+j].green = 153;
            matrix[size*((bound)+x1*bound)-size*(i)+(i+(y1*bound))+j].red = 51;
            matrix[size*((bound)+x1*bound)-size*(i)+(i+(y1*bound))+j].blue = 255;
        }
    }
}
void Draw::drawO(int x1,int y1){
    int thicken=(bound*0.04);
    int circle_radius=bound;
    int xmid = bound/2.0;
    int ymid = bound/2.0;
    for (int i = 0; i <bound ; ++i) {
        for (int j = 0; j <bound ; ++j) {
            int tempx = i;
            int tempy = j;
            for (int k = 0; k <thicken ; ++k) {
                if(pow((((i-xmid)*(i-xmid)+(j-ymid)*(j-ymid)-(((bound+k)*0.45)*((bound+k)*0.45)))),2)<=pow(bound,2)){
                    matrix[size*(i+x1*bound)+(j+(y1*bound))].green = 255;
                    matrix[size*(i+x1*bound)+(j+(y1*bound))].red = 153;
                    matrix[size*(i+x1*bound)+(j+(y1*bound))].blue = 51;
                }
            }
        }
    }
}
void Draw::border(){
    int thicken=(bound*0.02)+1;
    for (int i = size*0.02 ; i <size*0.98 ; ++i) {
        for (int j = size*0.02; j <size*0.98 ; ++j) {
            for (int k = 0; k <thicken; ++k) {
                if(i%bound==0||j%bound==0){
                    matrix[(size)*(j+k)+i+k].blue=255;
                    matrix[(size)*(j+k)+i+k].green=255;
                    matrix[(size)*(j+k)+i+k].red=255;
                }
            }

        }
    }
}