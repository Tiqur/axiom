#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./lib/Game.h"





int main() {
  std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::cout << "Input FEN: " << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  std::cout << game.currentBoardToFEN() << std::endl;

  // Render game
  game.render();

  

  //Pawn pawn = Pawn(8, true);
  //King king = King(18);
  //Rook rook = Rook(60);
  //Bishop bishop = Bishop(36);
  //Queen queen = Queen(36);
  //Knight knight = Knight(52);

  return 0;
}


