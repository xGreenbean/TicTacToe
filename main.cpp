
#include "TicTacToe.h"
#include "DummyPlayers.h"

#include "Champion.h"




int main() {
   Board board(3);
   board.fill('X');
    board.draw(800);
    return 0;
}
