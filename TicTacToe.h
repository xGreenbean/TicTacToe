//
// Created by ehud on 19/05/18.
//

#ifndef CPP_6_TICTACTOE_H
#define CPP_6_TICTACTOE_H
#include "Board.h"
#include "Player.h"

class TicTacToe {
    Board m_board;
    bool m_win;
    bool m_turn;
    Player * m_winner;
public:
     TicTacToe(int);
    Board play( Player&, Player&);
    void check_Board(vector<int>);
    Board board()const;
    const Player& winner() const;
    bool isfull();
};


#endif //CPP_6_TICTACTOE_H
