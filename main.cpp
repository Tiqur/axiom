#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <array>
#include "./lib/ChessPiece.h"
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./lib/Game.h"
#include "./lib/BoardRenderer.h"

// init renderer
BoardRenderer renderer = BoardRenderer();

void inputThread()
{
  std::string FEN = "8/8/8/8/8/8/3PPP2/3QKB2 w - - 0 1";
  std::cout << "Input FEN: " << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  game.highlightMovablePieces();
  game.highlightLegalMovesForPiecePos(60);
  renderer.setCustomSquareColors(game.getCustomSquareColors());
  renderer.setBoard(game.getBoard());

  //while (true)
  //{
  //  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  //  game.makeRandomMove();
  //  renderer.setCustomSquareColors(game.getCustomSquareColors());
  //  renderer.setBoard(game.getBoard());
  //}
}


int main() {
  // Cross thread board
  std::array<char, 64> board;

  // Start input thread
  std::thread t(&inputThread);

  // Render game
  if (renderer.Construct(512, 512, 1, 1))
    renderer.Start();

  return 0;
}


