//
// Created by ehud on 19/05/18.
//

#ifndef CPP_6_CHAMPION_H
#define CPP_6_CHAMPION_H
#include "Player.h"

class Champion : public Player{
public:
    const string name() const override { return "Ehud and Saimon"; }
    const vector<int> play(const Board &board)override;

};
#endif //CPP_6_CHAMPION_H
