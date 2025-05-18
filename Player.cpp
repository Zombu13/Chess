#include "Player.h"
#include <string>
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>




Player::Player(Piece::Color color, const Board& board)
    : _color(color), _board(board) {

    // Set up pawns
    size_t pawn_rank = (color == Piece::Color::white) ? 6 : 1;
    for (size_t file = 0; file < Board::SIZE; file++) {
        _pieces.push_back(new Pawn(color, _board.square_at(pawn_rank, file)));
    }

    // Set up back rank pieces
    size_t back_rank = (color == Piece::Color::white) ? 7 : 0;
    _pieces.push_back(new Rook(color, _board.square_at(back_rank, 0)));
    _pieces.push_back(new Knight(color, _board.square_at(back_rank, 1)));
    _pieces.push_back(new Bishop(color, _board.square_at(back_rank, 2)));
    _pieces.push_back(new Queen(color, _board.square_at(back_rank, 3)));

    // Create and store king
    _king = new King(color, _board.square_at(back_rank, 4));
    _pieces.push_back(_king);

    // Complete back rank
    _pieces.push_back(new Bishop(color, _board.square_at(back_rank, 5)));
    _pieces.push_back(new Knight(color, _board.square_at(back_rank, 6)));
    _pieces.push_back(new Rook(color, _board.square_at(back_rank, 7)));
}

Player::~Player() {
    for (Piece* piece : _pieces) {
        delete piece;
    }
}

Piece::Color Player::color() const {
    return _color;
}

bool Player::make_move(const std::string& from, const std::string& to) {
    try {
        Square& from_sq = _board.square_at(from);
        Square& to_sq = _board.square_at(to);

        if (!from_sq.is_occupied() ||
            from_sq.occupant()->color() != _color) {
            return false;
            }

        return from_sq.occupant()->move_to(to_sq);
    } catch (...) {
        return false;
    }
}

piece_value_t Player::piece_value() const {
    piece_value_t total = 0;
    for (const Piece* piece : _pieces) {
        if (piece->is_on_square()) {
            total += piece->value();
        }
    }
    return total;
}
