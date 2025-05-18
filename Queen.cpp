#include "Queen.h"
#include "Board.h"
#include <cmath>

//value method that returns the value of the Piece
piece_value_t Queen::value() const {
    return 9;
}

//checks if our Queen can move to the desired location
bool Queen::can_move_to(const Square& location) const
{
  // cant move our queen to the same location
    if (this->location() == &location)
  {
        return false;
    }

    // Get current and target coordinates
    size_t current_rank = this->location()->rank();
    size_t current_file = this->location()->file();
    size_t target_rank = location.rank();
    size_t target_file = location.file();

    // Calculate rank and file differences
    int rank_diff = static_cast<int>(current_rank) - static_cast<int>(target_rank);
    int file_diff = static_cast<int>(current_file) - static_cast<int>(target_file);

    // Queen can move any number of squares in a straight line or diagonal
    bool is_valid_move = false;

    // Check for straight line movement
    if ((current_rank == target_rank) || (current_file == target_file))
    {
        is_valid_move = true;
    }
    // Check for diagonal movement
    else if (std::abs(rank_diff) == std::abs(file_diff))
    {
        is_valid_move = true;
    }

    return is_valid_move;
}

//prints out our queen object
std::string Queen::str() const {
    // Unicode symbols
    if (color() == Piece::Color::white) {
        return "k";  // White queen
    } else {
        return "K";  // Black queen
    }
}
