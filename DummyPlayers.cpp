#pragma once
#include "DummyPlayers.h"


const vector<int> XYPlayer::play(const Board& board) {
    for (int x=0; x<board.size(); ++x) {
        for (int y=0; y<board.size(); ++y) {
            vector<int> c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}


const vector<int> YXPlayer::play(const Board& board) {
    for (int y=0; y<board.size(); ++y) {
        for (int x=0; x<board.size(); ++x) {
            vector<int> c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}



/**
 * The illegal player tries to put a char on a cell owned by the other player.
 */
const vector<int> IllegalPlayer::play(const Board& board) {
    char charOfOtherPlayer = (
            myChar=='X'? 'O': 'X'
    );
    for (int y=0; y<board.size(); ++y) {
        for (int x=0; x<board.size(); ++x) {
            vector<int> c{x,y};
            if (board[c]==charOfOtherPlayer) {
                return c;
            }
        }
    }
    return {0,0};  // did not find an illegal square - play on the top-left
}


const vector<int> ExceptionPlayer::play(const Board& board) {
    throw string("hahaha");
}