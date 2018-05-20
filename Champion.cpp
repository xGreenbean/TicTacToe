//
// Created by ehud on 20/05/18.
//
#include "Champion.h"
#include "Board.h"
const vector<int> Champion::play(const Board &board) {
    for (int i = 0; i < board.size(); ++i) {
        board[{ board.size()-1,i}]=myChar;
    }
    return {board.size()-1,board.size()-1};

}
