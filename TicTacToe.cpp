#include "TicTacToe.h"

//
// Created by ehud on 19/05/18.
//
TicTacToe::TicTacToe(int dim) {
    m_board.init_Board(dim);
    m_win=false;
    m_turn= true;
    m_winner= nullptr;
}
Board TicTacToe::play( Player& p1,  Player& p2) {
    m_board='.';
    m_win=false;
    p1.setChar('X');
    p2.setChar('O');
    m_turn=true;
    m_winner=&p2;
    while(!m_win){
        if(m_turn){
            try {
                vector<int> v;
                v = p1.play(m_board);
                if (m_board[v] == p2.myChar)
                    throw std::string("Illegal Player");
                m_board[v]='X';
                check_Board(v);
                if(m_win) {
                    m_winner = &p1;
                }
            }catch (...){
                m_winner=&p2;
                m_win=true;
                return m_board;
            }
        }else{
            try {
                vector<int> v;
                v = p2.play(m_board);
                if (m_board[v] == p1.myChar)
                    throw std::string("Illegal Player");
                m_board[v]='O';
                check_Board(v);
                if(m_win){
                    m_winner=&p2;
                }
            }catch (...){
                m_winner=&p1;
                m_win=true;
                return m_board;
            }

        }
    }
    return m_board;


}
void  TicTacToe::check_Board(vector<int> vector1){
    char move;
    switch (m_turn){
        case true:
            move='X';
            break;
        case false:
            move='O';
            break;
    }
    int counter =0;
    /*check column*/
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={vector1.at(0),vector1.at(1)};
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }
//    cout<<counter<<endl;
    if(counter==m_board.size()){
        m_win=true;
        return;
    }
//    cout<<counter<<endl;
    /*check row*/
    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={vector1.at(0),vector1.at(1)};
        v.at(1)=i;
        if(move==m_board[v].get_p())counter++;
    }
//    cout<<counter<<endl;
    if(counter==m_board.size()){
        m_win=true;
        return;
    }
    /*if on diagonals check diagonals*/
    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={0,0};
        v.at(1)=i;
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }
//    cout<<counter<<endl;
    if(counter==m_board.size()){
        m_win=true;
        return;
    }
    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={0,0};
        v.at(1)=m_board.size()-1-i;
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }
//    cout<<counter<<endl;
    if(counter==m_board.size()){
        m_win=true;
        return;
    }
    m_turn=!m_turn;
}
Board TicTacToe::board() const{

    return m_board;
}
const Player& TicTacToe::winner() const {
    return *m_winner;
}
bool TicTacToe::isfull(){
    for (int i = 0; i <m_board.size() ; ++i) {
        for (int j = 0; j <m_board.size() ; ++j) {
            if(m_board[{i,j}].get_p()=='.')return false;
        }
    }
}
#include "TicTacToe.h"
