#include <iostream>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./BoardRenderer.h"

void parseFEN(char* FEN, char* board, bool turn)
{
  // Board index
  char index = 0;

  // Set game board
  for (int i = 0; FEN[i] != ' '; i++)
  {
    if (FEN[i] != '/')
    {
      // Fill empty squares with 0
      if (isdigit(FEN[i])) 
        // Convert FEN[i] to digit from ascii
        for (int o = 0; o<FEN[i]-48; o++)
          board[index++] = '+';
      // Assign piece to board position
      else
        board[index++] = FEN[i];
    }
  }

  // Output board to console
  for (int x = 0; x<8; x++) {
    for (int y = 0; y<8; y++)
      std::cout << ' ' << board[x*8 + y];
    std::cout << std::endl;
  }
};


int main() {
    char FEN[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << FEN << std::endl;

    // Holds all positions on board
    char board[64];

    // Turn (true for white)
    bool turn;

    // Parse FEN into board positions
    parseFEN(FEN, board, turn);

    // Init renderer
    BoardRenderer renderer = BoardRenderer(board);

       
    // Start renderer
    if (renderer.Construct(1120, 1120, 2, 2))
      renderer.Start();
    

    //Pawn pawn = Pawn(8, true);
    //King king = King(18);
    //Rook rook = Rook(60);
    //Bishop bishop = Bishop(36);
    //Queen queen = Queen(36);
    //Knight knight = Knight(52);

    return 0;
}


