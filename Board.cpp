#include "Board.h"
#include "Piece.h"
#include "Square.h"
#include <stdexcept>
#include <cctype>

std::ostream& operator<<(std::ostream& os, const Board& board);

//Constructor for the board
Board::Board()
{
  //use nested for loops to place all the squares in the board
    for (size_t rank = 0; rank < SIZE; rank++)
  {
        for (size_t file = 0; file < SIZE; file++)
      {
            _squares[rank][file] = new Square(rank, file);
        }
    }
}

//destructor for the board
Board::~Board()
{
  //nested loops that destruct all squares
    for (size_t rank = 0; rank < SIZE; rank++)
  {
        for (size_t file = 0; file < SIZE; file++)
      {
            delete _squares[rank][file];
        }
    }
}

//finds the square at a rank and file in the board
Square& Board::square_at(size_t rank, size_t file) const
{
  //check if the rank is valid
    if (rank >= SIZE || file >= SIZE)
  {
        throw std::out_of_range("invalid");
    }
    //return the square we are looking for
    return *_squares[rank][file];
}

//finds us the square at an identifier like a8
Square& Board::square_at(const std::string& identifier) const
{
    char file = tolower(identifier[0]);
    char rank = identifier[1];

    size_t file_idx = file - 'a';
    size_t rank_idx = SIZE - (rank - '0');

    return square_at(rank_idx, file_idx);
}

// make sure that there is a valid rank
bool Board::is_valid_rank(const Square& from, const Square& to) const
{
    return from.rank() == to.rank();
}

//check for a valid file
bool Board::is_valid_file(const Square& from, const Square& to) const
{
    return from.file() == to.file();
}

//check for valid diag
bool Board::is_valid_diag(const Square& from, const Square& to) const
{
    int rankDiff = static_cast<int>(from.rank()) - static_cast<int>(to.rank());
    int fileDiff = static_cast<int>(from.file()) - static_cast<int>(to.file());
    return abs(rankDiff) == abs(fileDiff);
}

//check if there are any pieces in the rank
bool Board::is_clear_rank(const Square& from, const Square& to) const
{
    if (!is_valid_rank(from, to))
      {
      return false;
      }

    size_t rank = from.rank();

    //create start and end variables for traversal
    size_t startFile = std::min(from.file(), to.file());
    size_t endFile = std::max(from.file(), to.file());

    // Check all squares between start and end
    for (size_t file = startFile + 1; file < endFile; file++)
    {
        if (_squares[rank][file]->occupant() != nullptr)
        {
            return false;
        }
    }
    return true;
}

//check if there are any pieces within the file
bool Board::is_clear_file(const Square& from, const Square& to) const
{
    if (!is_valid_file(from, to)) {
      return false;
      }

    size_t file = from.file();
    size_t startRank = std::min(from.rank(), to.rank());
    size_t endRank = std::max(from.rank(), to.rank());

    // Check all squares between
    for (size_t rank = startRank + 1; rank < endRank; rank++)
    {
        if (_squares[rank][file]->occupant() != nullptr)
        {
            return false;
        }
    }
    return true;
}

//check if the diagonal row is clear
bool Board::is_clear_diag(const Square& from, const Square& to) const
{
    if (!is_valid_diag(from, to)) {
      return false;
      }

    int rankStep = (to.rank() > from.rank()) ? 1 : -1;
    int fileStep = (to.file() > from.file()) ? 1 : -1;

    size_t rank = from.rank() + rankStep;
    size_t file = from.file() + fileStep;

    while (rank != to.rank() && file != to.file())
    {
        if (_squares[rank][file]->occupant() != nullptr)
        {
            return false;
        }
        rank += rankStep;
        file += fileStep;
    }
    return true;
}

//print out the whole board
std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << "  a b c d e f g h\n";
    os << " +---+---+---+---+---+---+---+---+\n";

    for (size_t rank = 0; rank < Board::SIZE; rank++) {
        os << (Board::SIZE - rank) << "|";
        for (size_t file = 0; file < Board::SIZE; file++) {
            // Access through the public square_at() method instead of _squares
            os << " " << board.square_at(rank, file) << " |";
        }
        os << " " << (Board::SIZE - rank) << "\n";
        os << " +---+---+---+---+---+---+---+---+\n";
    }

    os << "  a b c d e f g h\n";
    return os;
}
