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
  std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::cout << "Input FEN: " << FEN << std::endl;

  // Create new Game instance
  Game game = Game(FEN);
  renderer.setBoard(game.getBoard());
  //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  //while (true)
    //std::cout << std::rand() << std::endl;
}


int main() {
  // Cross thread board
  std::array<char, 64> board;

  // Start input thread
  std::thread t(&inputThread);

  // Render game
  if (renderer.Construct(128, 128, 1, 1))
    renderer.Start();

  return 0;
}


