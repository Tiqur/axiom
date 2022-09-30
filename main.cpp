#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "./lib/ChessPiece.h"
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./lib/Game.h"


int main() {
  std::string FEN = "8/3p1p2/6P1/4N3/6P1/8/8/8 w - - 0 1";
  std::cout << "Input FEN: " << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  std::cout << game.currentBoardToFEN() << std::endl;

  King a = King(game.getBoard(), 28);
  for (auto s: a.getTargetedSquares())
  {
    std::cout << (int)s << std::endl;
  }

  // Render game
  //game.render();


  return 0;
}


