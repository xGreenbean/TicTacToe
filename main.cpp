
#include "TicTacToe.h"
#include "DummyPlayers.h"

#include "Champion.h"




int main() {
    Board board(30);
    board.fill('.');
//    cin >> board;
    string filename = board.draw(1000);
    cout << filename << endl;
}
