#include "Square.h"
#include "Piece.h"
#include <iostream>

//returns the rank of the Square
size_t Square::rank() const
{
    return _rank;
}

//returns the file of the Square
size_t Square::file() const
{
    return _file;
}

//checks if the square is occupied
bool Square::is_occupied() const
{
    return _occupant != nullptr;
}

//return the Piece that is in the square
Piece* Square::occupant() const
{
    return _occupant;
}

//sets the occupant on a square
void Square::set_occupant(Piece* occupant)
{
    _occupant = occupant;
}

//prints the square out and what is on the square
std::ostream& operator<<(std::ostream& os, const Square& square)
{
    if (square.is_occupied()) {
        os << *square.occupant();
    } else {
        os << " ";
    }
    return os;
}
