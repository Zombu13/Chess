#include "Pawn.h"
#include "Square.h"
#include <cmath>

//value method that prints the value of the pawn
piece_value_t Pawn::value() const
{
    return 1;
}

//boolean method that checks if our pawn can move to the location
bool Pawn::can_move_to(const Square& location) const
{
    if (!this->location()) return false;

    // Get current and target coordinates
    int current_rank = static_cast<int>(this->location()->rank());
    int current_file = static_cast<int>(this->location()->file());
    int target_rank = static_cast<int>(location.rank());
    int target_file = static_cast<int>(location.file());

    // Pawns move differently based on color
    if (color() == Piece::Color::white)
    {
        // White pawns move up
        if (current_file == target_file)
        {
            // Single square move
            if (current_rank - target_rank == 1)
            {
                return true;
            }

        }
    } else
    {
        // Black pawns move down
        if (current_file == target_file)
        {
            // Single square
            if (target_rank - current_rank == 1)
            {
                return true;
            }

        }
    }

    return false;
}

//move to method that moves our pawn using the method from our Piece class
bool Pawn::move_to(Square& location)
{
    if (!can_move_to(location)) return false;

    if (location.is_occupied()) {
        location.occupant()->capture();
    }

    set_location(&location);
    _moved = true;
    return true;
}

//Prints out pawn object and whether it was white and black
std::string Pawn::str() const {

    if (color() == Piece::Color::white) {
        return "k";  // White pawn
    } else {
        return "K";  // Black pawn
    }
}
