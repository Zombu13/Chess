#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"

class Pawn : public Piece {
  public:
    Pawn(Piece::Color color, Square& location) : Piece(color, location) { }

    piece_value_t value() const override;

    bool can_move_to(const Square& location) const override;
    virtual bool move_to(Square& location) override;

    std::string str() const override;

  private:
    bool _moved = false;
};

#endif
