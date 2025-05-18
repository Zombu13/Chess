#include "Piece.h"
#include "Square.h"
#include <iostream>

//returns the color of the piece
Piece::Color Piece::color() const
{
    return _color;
}

//returns the location of our piece and returns the square of it
Square* Piece::location() const
{
    return _location;
}

//sets the location of the piece
void Piece::set_location(Square* location)
{
    if (_location) {
        _location->set_occupant(nullptr);
    }
    _location = location;
    if (_location) {
        _location->set_occupant(this);
    }
}

//boolean that checks if there is a Piece on the square
bool Piece::is_on_square() const
{
    return _location != nullptr;
}

//bool method that moves us to a location or returns false if we cant
bool Piece::move_to(Square& location)
{
    // Check if the move is valid
    if (!can_move_to(location))
    {
        return false;
    }

    // Handle capturing if the target square is occupied
    if (location.is_occupied())
    {
        // Only capture pieces of the opposite color
        if (location.occupant()->color() == _color) {
            return false;  // Can't capture your own pieces
        }
        location.occupant()->capture();
    }

    // Perform the move
    set_location(&location);
    return true;
}

//capture method that sets the piece to null
void Piece::capture()
{
    set_location(nullptr);
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << piece.str();
    return os;
}
