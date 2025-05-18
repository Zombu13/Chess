#include "Bishop.h"
#include "Square.h"
#include <cmath>

//returns the value of the Bishop
piece_value_t Bishop::value() const
{
    return 3;
}

//boolean method that checks if the Bishop can moved to the desired location
bool Bishop::can_move_to(const Square& location) const
{
    //Bishop cant move to the spot it is currently on
    if (this->location() == &location)
    {
        return false;
    }

    // Get current and target coordinates
    int current_rank = static_cast<int>(this->location()->rank());
    int current_file = static_cast<int>(this->location()->file());
    int target_rank = static_cast<int>(location.rank());
    int target_file = static_cast<int>(location.file());

    //rank and file differences
    int rank_diff = std::abs(current_rank - target_rank);
    int file_diff = std::abs(current_file - target_file);

    // Bishop moves diagonally any number of squares
    return rank_diff == file_diff;
}

std::string Bishop::str() const
{
    if (color() == Piece::Color::white) {
        return "k";  // White bishop
    } else {
        return "K";  // Black bishop
    }
}
