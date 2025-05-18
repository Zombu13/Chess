#include "Knight.h"
#include "Square.h"
#include <cmath>

//value method that prints the value of the Knight
piece_value_t Knight::value() const
{
    return 3;
}

//boolean method that looks to see if our knight can move to location
bool Knight::can_move_to(const Square& location) const
{
    if (this->location() == &location)
    {
        return false;
    }

    // Get current and target coordinates
    int current_rank = static_cast<int>(this->location()->rank());
    int current_file = static_cast<int>(this->location()->file());
    int target_rank = static_cast<int>(location.rank());
    int target_file = static_cast<int>(location.file());

    // Calculate rank and file differences
    int rank_diff = std::abs(current_rank - target_rank);
    int file_diff = std::abs(current_file - target_file);

    // Knight moves in an L-shape
    return (rank_diff == 2 && file_diff == 1) ||
           (rank_diff == 1 && file_diff == 2);
}

//prints out the Knight object
std::string Knight::str() const
{

    if (color() == Piece::Color::white) {
        return "n";  // White knight
    } else {
        return "N";  // Black knight
    }
}
