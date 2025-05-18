#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

class King : public Piece {
  public:
    explicit King(Piece::Color color, Square& location) : Piece(color, location) { }

    piece_value_t value() const override;

    bool can_move_to(const Square& location) const override;

    std::string str() const override;
};

#endif
