#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Board.h"
#include "Piece.h"
#include "King.h"

class Player {
  public:
    Player(Piece::Color color, const Board& board);

    Piece::Color color() const;

    bool make_move(const std::string& from, const std::string& to);
    piece_value_t piece_value() const;

    ~Player();

  private:
    const Piece::Color _color;
    const Board& _board;
    std::vector<Piece*> _pieces;
    King* _king;

};

#endif

