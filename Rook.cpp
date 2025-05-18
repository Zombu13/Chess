#include "Rook.h"
#include "Square.h"
#include <cmath>

//value method that returns the value of the rook
piece_value_t Rook::value() const
{
    return 5;
}

//bool method that checks if we can move our rook to the location
bool Rook::can_move_to(const Square& location) const
{
    if (!this->location()) return false;

    // Get current and target coordinates
    size_t current_rank = this->location()->rank();
    size_t current_file = this->location()->file();
    size_t target_rank = location.rank();
    size_t target_file = location.file();

    // Rook can move any number of squares in a straight line
    return (current_rank == target_rank) || (current_file == target_file);
}

//prints the Rook object
std::string Rook::str() const
{

    if (color() == Piece::Color::white) {
        return "k";  // White rook
    } else {
        return "K";  // Black rook
    }


}
