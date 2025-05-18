#include "King.h"
#include "Square.h"
#include <cmath>

//returns the value of the King piece
piece_value_t King::value() const
{
    return 200;
}

//boolean method that checks if the King can move to a desired location
bool King::can_move_to(const Square& location) const {

  //cant move to the same location
    if (this->location() == &location)
    {
        return false;
    }

    //get the current and target ranks and files
    size_t current_rank = this->location()->rank();
    size_t current_file = this->location()->file();
    size_t target_rank = location.rank();
    size_t target_file = location.file();

    // Calculate rank and file differences
    int rank_diff = static_cast<int>(current_rank) - static_cast<int>(target_rank);
    int file_diff = static_cast<int>(current_file) - static_cast<int>(target_file);

    // King can move one square in any direction
    return (std::abs(rank_diff) <= 1 && std::abs(file_diff) <= 1);
}

//prints out the King object
std::string King::str() const
{

    if (color() == Piece::Color::white) {
        return "k";  // White king
    } else {
        return "K";  // Black king
    }


}
