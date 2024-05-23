#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "ship.h"

/**
 * Class that implements a player of the game.
 */
class Player
{
private:
    string name;
    Ship ships[10]; // the ships of the player
    int numShips; // the number of ships of the player (initialized to 0 and incremented when ships are added)
    Square grid[10][10]; // the grid of the player
    Square opponentGrid[10][10]; // the grid of the opponent, used to keep track of the hits of the player

public:
    /**
     * Initializes a player setting the index and the name. The numShips variable is also initialized to zero.
     * Finally, for all grid positions and for all opponentGrid positions, their coordinates are set using the
     * setCoordinates method.
     *
     * Hint: we can set the coordinates of the square (2, 3) using the command grid[2][3].setCoordinates(2, 3);
     *
     * @param playerName the name of the player.
     */
    Player(string playerName);

    /**
     * Returns the name of the player.
     *
     * @return the name of the player.
     */
    string getName();

    /**
     * Returns the number of ships of the player that are sunk.
     *
     * Hint: we can use the isSunk method to check if a ship is sunk.
     *
     * @return the number of ships of the player that are sunk.
     */
    int numberOfShipsThatAreSunk();

    /**
     * Accepts a hit at the location provided. Note that this method declares the hit two times.
     * It first calls the hitSquare method of the relevant grid square.
     * And then it finds the ship that occupies the square (using the hasSquare method) and
     * calls the hit method of the ship.
     *
     * @param x the horizontal coordinate of the hit.
     * @param y the vertical coordinate of the hit.
     * @return true if there is a ship in the square, or false otherwise.
     */
    bool acceptHit(int x, int y);

    /**
     * Guesses a square for the player randomly. This method continuously guesses a square
     * until it finds a non-hit square at the opponentGrid. When a valid guess is found,
     * the hitSquare method is called for the square of the opponentGrid. Finally, the method
     * returns the square that is guessed.
     *
     * Hint: we may use a loop so that we keep guessing until the guessed square is not already hit at the opponentGrid.
     *
     * @return the square that is guessed by the player.
     */
    Square guessSquare();

    /**
     * Places a ship of the player facing right given its position and its size. This method iterates over all
     * squares from left to right and does two actions. The first is to call the addShip in each of these squares,
     * and the second is to call the addSquare for the ship.
     *
     * Hint: we have to create a loop so that we find the squares to be occupied by the ship. The loop for a
     *       ship of size 3 that is placed in (2, 3) would have to iterate over squares (2, 3), (2, 4), (2, 5).
     *
     * @param x the horizontal coordinate of the hit.
     * @param y the vertical coordinate of the hit.
     * @param shipSize the size of the ship (as number of squares).
     */
    void placeShipFacingRight(int x, int y, int shipSize);

    /**
     * Places a ship of the player facing downwards given its position and its size. This method iterates over all
     * squares from left to right and does two actions. The first is to call the addShip in each of these squares,
     * and the second is to call the addSquare for the ship.
     *
     * Hint: we have to create a loop so that we find the squares to be occupied by the ship. The loop for a
     *       ship of size 3 that is placed in (2, 3) would have to iterate over squares (2, 3), (3, 3), (4, 3).
     *
     * @param x the horizontal coordinate of the hit.
     * @param y the vertical coordinate of the hit.
     * @param shipSize the size of the ship (as number of squares).
     */
    void placeShipFacingDown(int x, int y, int shipSize);

    /**
     * Places a ship of the player given its position, its direction, and its size. Calls the
     * method placeShipFacingRight or the method placeShipFacingDown according to the direction
     * of the placement (r for right or d for down).
     *
     * @param x the horizontal coordinate of the hit.
     * @param y the vertical coordinate of the hit.
     * @param shipDirection the direction of the ship as a char ('r' or 'd').
     * @param shipSize the size of the ship (as number of squares).
     */
    void placeShip(int x, int y, char shipDirection, int shipSize){
        if (shipDirection == 'r')
            placeShipFacingRight(x, y, shipSize);
        else if (shipDirection == 'd')
            placeShipFacingDown(x, y, shipSize);
        else
            cout << "Error in ship placement!" << endl;
        numShips++;
    }

    /**
     * Places the ships of the player in different positions in the player's grid.
     * Calls the placeShip method for each ship placement, giving as input the coordinates (x, y),
     * the direction (r for right or d for down) and the size of the ship.
     */
    void placeShips() {
        placeShip(9, 4, 'r', 6);
        placeShip(0, 6, 'r', 4);
        placeShip(2, 0, 'd', 4);
        placeShip(0, 3, 'd', 3);
        placeShip(2, 5, 'r', 3);
        placeShip(5, 9, 'd', 3);
        placeShip(0, 0, 'r', 2);
        placeShip(5, 5, 'd', 2);
        placeShip(2, 9, 'd', 2);
        placeShip(7, 0, 'r', 2);
    };

    /**
     * Returns a string representation of the player's grid.
     *
     * @param hide boolean indicating whether the ships should be shown (false) or remain hidden (true).
     * @return the grid of the player as string.
     */
    string gridToString(bool hide) {
        stringstream sstm;
        sstm << "     _______________________ \n"
             << "    |                       |\n"
             << "    |   0 1 2 3 4 5 6 7 8 9 |\n"
             << "    |                       |\n";
        for(int i = 0; i < 10; i++) {
            sstm << "    | " << ((char)('A' + i)) << " ";
            for(int j = 0; j < 10; j++) {
                if(grid[i][j].hasShip() && grid[i][j].isHit()) sstm << "# ";
                else if(!grid[i][j].hasShip() && grid[i][j].isHit()) sstm << "+ ";
                else if(grid[i][j].hasShip() && !hide) sstm << "# ";
                else sstm << "- ";
            }
            sstm << "|\n";
        }
        sstm << "    |_______________________|";
        string result = sstm.str();
        return result;
    };
};

#endif // PLAYER_H
