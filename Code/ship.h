#ifndef SHIP_H
#define SHIP_H

#include "square.h"

/**
 * Class that implements a ship of the game.
 */
class Ship
{
private:
    Square squares[6]; // the squares of the ship
    int numSquares; // the number of squares of the ship (initialized to 0 and incremented when squares are added)
    int numHits; // the number of hits that the ship has accepted (initialized to 0 and incremented when the ship is hit)

public:
    /**
     * Initializes a ship setting its size, its number of squares occupied and its
     * number of hits accepted to zero.
     */
    Ship();

    /**
     * Returns the number of squares occupied by the ship.
     *
     * @return the number of squares occupied by the ship.
     */
    int getNumberOfSquares();

    /**
     * Adds the given square to the ship and then increments the number of squares.
     *
     * @param square the square to be added to the ship.
     */
    void addSquare(Square square);

    /**
     * Checks if the ship occupies a specific square that is given.
     *
     * Hint: we can use the equals method of the Square to check if the square given is equal to another square.
     *
     * @param square the square to be checked if it occupies the ship.
     * @return true if the ship occupies the square that is given, or false otherwise.
     */
    bool hasSquare(Square square);

    /**
     * Increases the number of hits by one.
     */
    void hit();

    /**
     * Checks if the number of hits is equal to the size of the ship
     *
     * @return true if the number of hits is equal to the number of squares occupied by the ship, or false otherwise.
     */
    bool isSunk();
};

#endif
