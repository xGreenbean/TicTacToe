//
// Created by ehud on 19/05/18.
//

#ifndef CPP_6_DUMMYPLAYERS_H
#define CPP_6_DUMMYPLAYERS_H
#pragma once
#include "Player.h"
/*
	This player scans the board looping on x then on y,
	and plays on the first empty cell.
*/
class XYPlayer: public Player {
public:
    const string name() const override { return "XYPlayer"; }

    /**
     * Selects a single place to put my symbol, given the current board.
     * Defines the strategy of the player.
     */
    const vector<int> play(const Board& board) override;
};


/*
	This player scans the board looping on y then on x,
	and plays on the first empty cell.
*/
class YXPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const vector<int> play(const Board& board) override;
};


/*
   This player makes illegal moves -
   it tries to override cells of the other player.
   It should always lose.
*/
class IllegalPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const  vector<int> play(const Board& board) override;
};


/*
	This player always throws an exception.
	It should always lose.
*/
class ExceptionPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const vector<int> play(const Board& board) override;
};


#endif //CPP_6_DUMMYPLAYERS_H
