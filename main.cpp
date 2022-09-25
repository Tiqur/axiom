#include <iostream>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./Axiom.h"


int main() {
    char startingPosition[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << startingPosition << std::endl;

    Axiom game = Axiom(startingPosition);
    if (game.Construct(1120, 1120, 2, 2))
      game.Start();

    //Pawn pawn = Pawn(8, true);
    //King king = King(18);
    //Rook rook = Rook(60);
    //Bishop bishop = Bishop(36);
    //Queen queen = Queen(36);
    //Knight knight = Knight(52);

    return 0;
}


