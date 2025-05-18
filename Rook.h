#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "Piece.h"

class Rook : public Piece {
  public:
    Rook(Piece::Color color, Square& location) : Piece(color, location) { }

    piece_value_t value() const override;

    bool can_move_to(const Square& location) const override;

    std::string str() const override;
};

#endif
