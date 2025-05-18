#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Square;

typedef unsigned int piece_value_t;

class Piece {
  public:
    enum struct Color {
        black, white
    };

    Piece(const Piece::Color color, Square& location) : _color(color) {
        this->set_location(&location);
    }

    virtual piece_value_t value() const = 0;
    Piece::Color color() const;

    Square* location() const;
    void set_location(Square* location);
    bool is_on_square() const;

    virtual bool can_move_to(const Square& location) const = 0;
    virtual bool move_to(Square& location);
    void capture();

    virtual std::string str() const = 0;

    virtual ~Piece() = default;

  private:
    const Piece::Color _color;
    Square* _location = nullptr;
};

std::ostream& operator<<(std::ostream& os, const Piece& piece);

#endif
