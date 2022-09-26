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
#include "./lib/BoardRenderer.h"





int main() {
  std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::cout << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  game.outputCurrentBoard();


  std::cout << game.getTurn() << std::endl;
  std::cout << game.getHalfMoveClock() << std::endl;
  std::cout << game.getFullMoveCounter() << std::endl;

  // Init renderer
  BoardRenderer renderer = BoardRenderer(game.getBoard());

     
  // Start renderer
  //if (renderer.Construct(1120, 1120, 2, 2))
    //renderer.Start();
  

  //Pawn pawn = Pawn(8, true);
  //King king = King(18);
  //Rook rook = Rook(60);
  //Bishop bishop = Bishop(36);
  //Queen queen = Queen(36);
  //Knight knight = Knight(52);

  return 0;
}


