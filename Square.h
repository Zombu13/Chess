#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Piece.h"

class Square {
  public:
    Square(size_t rank, size_t file) : _rank(rank), _file(file) { }

    size_t rank() const;
    size_t file() const;

    bool is_occupied() const;
    Piece* occupant() const;

  private:
    void set_occupant(Piece* occupant);
    const size_t _rank;
    const size_t _file;
    Piece* _occupant = nullptr;
    friend void Piece::set_location(Square* location);
    friend void Piece::capture();
};

std::ostream& operator<<(std::ostream& os, const Square& square);

#endif
