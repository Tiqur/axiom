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
  std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::cout << "Input FEN: " << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  std::cout << game.currentBoardToFEN() << std::endl;
  game.makeRandomMove();
  game.makeRandomMove();

  // Render game
  game.render();


  return 0;
}


