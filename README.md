# Chess Project Overview

## Board

- The board is square with size `N x N` (e.g., a size of 8 indicates an 8×8 board).
- Internally, the board contains a statically allocated 2D array of pointers to `Square` objects:  
  `Square* _squares[8][8]`.  
  This array is initialized to `nullptr` by default.
- The constructor dynamically allocates 64 `Square` objects and stores their addresses in the array.
- The destructor deallocates each dynamically allocated `Square`.

### Clear Methods

- `is_clear_rank`, `is_clear_file`, and `is_clear_diagonal` methods:
  - Return `true` if the path between two squares is valid for that type (rank, file, diagonal).
  - The path must be unoccupied—i.e., all intermediate squares contain no piece.

### Board Output Format

The board can be printed in a simple, plain-text format that resembles traditional chess layout:

   a   b   c   d   e   f   g   h
 +---+---+---+---+---+---+---+---+
8|   |   |   |   |   |   |   |   | 8
 +---+---+---+---+---+---+---+---+
7|   |   |   |   |   |   |   |   | 7
 +---+---+---+---+---+---+---+---+
6|   |   |   |   |   |   |   |   | 6
 +---+---+---+---+---+---+---+---+
5|   |   |   |   |   |   |   |   | 5
 +---+---+---+---+---+---+---+---+
4|   |   |   |   |   |   |   |   | 4
 +---+---+---+---+---+---+---+---+
3|   |   |   |   |   |   |   |   | 3
 +---+---+---+---+---+---+---+---+
2|   |   |   |   |   |   |   |   | 2
 +---+---+---+---+---+---+---+---+
1|   |   |   |   |   |   |   |   | 1
 +---+---+---+---+---+---+---+---+
   a   b   c   d   e   f   g   h


   
- Internally, `_squares[0][0]` corresponds to square **a8**, `_squares[1][0]` to **a7**, `_squares[2][1]` to **b6**, etc.
- Each empty square prints as a single space `' '`, followed by a space for formatting.

## Square

- Each `Square` object knows its:
  - **Rank** (row)
  - **File** (column)
- Once set, rank and file values are constant.
- Each square may hold one **occupant**, a pointer to a `Piece`.
  - `nullptr` means the square is unoccupied.
- Occupants are not set directly. Instead:
  - A `Piece` updates its location.
  - The square grants `Piece::set_location()` friend access to set its occupant.
- Outputting a square means:
  - If occupied, output the `Piece`'s symbol.
  - If not, output a space `' '`.

## Piece and Derived Types

- Each `Piece` has:
  - A **Color**: `Piece::Color::black` or `Piece::Color::white` (defined using a scoped enum).
  - A **Value** (e.g., king = 200, others standard values).
    - Value is not stored but returned when needed.
  - A pointer to its **current square** (or `nullptr` if not placed).
- Movement:
  - `can_move_to(Square*)` checks whether a move is valid *in principle*, assuming an empty board.
  - Each piece follows standard chess movement rules for its type (e.g., bishop moves diagonally).
  - Special rules (castling, en passant, pawn promotion, etc.) are not yet implemented.
- Movement execution:
  - Updates the piece's location and the source/destination squares.
  - If the destination square is occupied:
    - The existing piece sets its location to `nullptr` (effectively removed from board).
    - This models a basic "capture" mechanism.
- Construction:
  - All pieces must be placed on a square upon creation.
  - You should create at least one of each piece type (black & white) for testing.
- Outputting a piece:
  - Use a single Unicode or ASCII character.
  - Unicode: ♔, ♕, ♖, ♗, ♘, ♙ (and black versions)
  - ASCII (fallback):
    - K (king), Q (queen), R (rook), B (bishop), N (knight), P (pawn)
    - Uppercase for black, lowercase for white (e.g., `K` = black king, `n` = white knight)

## Implementation Notes

- All classes and methods are documented with Doxygen comments.
- Inline comments are added for complex logic.


  
