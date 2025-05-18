#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "Piece.h"

class Queen : public Piece {
  public:
    Queen(Piece::Color color, Square& location) : Piece(color, location) { }

    piece_value_t value() const override;

    bool can_move_to(const Square& location) const override;

    std::string str() const override;
};

#endif
