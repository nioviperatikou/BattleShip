#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

void printGridsSideBySide(string player1, string player2, string grid1, string grid2) {
    cout << "     " << player1 << setw(29) << player2 << endl;
    stringstream ss(grid1), ss2(grid2);
    string to, to2;
    while(getline(ss, to, '\n') && getline(ss2, to2, '\n'))
        cout << to << to2 << endl;
    cout << endl;
}

int main() {
    srand(time(NULL));

    Player players[2] = {Player("Player 1"), Player("Player 2")};

    // Set up the ships on the grid
    players[0].placeShips();
    players[1].placeShips();

    int playerTurn = 0;
    do {
        cout << "Turn of " << players[playerTurn].getName() << endl << endl;
        printGridsSideBySide(players[0].getName(), players[1].getName(), players[0].gridToString(playerTurn != 0), players[1].gridToString(playerTurn == 0));

        // Guess position
        Square p = players[playerTurn].guessSquare();
        cout << players[playerTurn].getName() << " shoots at " << p.toString();
        if (players[1 - playerTurn].acceptHit(p.getX(), p.getY()))
            cout << ". It's a Hit!" << endl << endl;
        else
            cout << ". It's a Miss!" << endl << endl;

        printGridsSideBySide(players[0].getName(), players[1].getName(), players[0].gridToString(playerTurn != 0), players[1].gridToString(playerTurn == 0));

        playerTurn = 1 - playerTurn;
    } while (!(players[0].numberOfShipsThatAreSunk() == 10 || players[1].numberOfShipsThatAreSunk() == 10));

    if (players[0].numberOfShipsThatAreSunk() == 10)
        cout << players[1].getName() << " has won!" << endl;
    else
        cout << players[0].getName() << " has won!" << endl;

    return 0;
}
