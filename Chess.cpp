#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>

int main() {
    Board board;
    Player white(Piece::Color::white, board);
    Player black(Piece::Color::black, board);

    Player* current = &white;
    Player* opponent = &black;

    for (int turn = 1; turn <= 20; turn++) {
        std::cout << "Turn " << turn << " - "
                  << (current == &white ? "White" : "Black") << "'s move\n";
        std::cout << board << "\n";

        std::string from, to;
        bool valid_move = false;

        while (!valid_move) {
            std::cout << "Enter move (e.g., 'a2 a4'): ";
            std::cin >> from >> to;

            valid_move = current->make_move(from, to);
            if (!valid_move) {
                std::cout << "Invalid move. Try again.\n";
            }
        }

        std::swap(current, opponent);
    }

    std::cout << "Final board:\n" << board << "\n";
    std::cout << "White pieces value: " << white.piece_value() << "\n";
    std::cout << "Black pieces value: " << black.piece_value() << "\n";

    return 0;
}
