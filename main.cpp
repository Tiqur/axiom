#include <iostream>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"


struct Game 
{
  // Entire board
  char board[64];

  // True = white
  bool turn = true;

  Game(char* FEN, bool turn)
  {
    // Set game turn
    turn = turn;

    // Set game board
    //for (int i = 0; FEN[i] != ' '; i++)
    //{
    //  std::cout << FEN[i] << std::endl;
    //}
  }


  
};


int main() {
    char startingPosition[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << startingPosition << std::endl;


    Game game = Game(startingPosition, true);
    //Pawn pawn = Pawn(8, true);
    //King king = King(18);
    //Rook rook = Rook(60);
    //Bishop bishop = Bishop(36);
    Queen queen = Queen(36);

    return 0;
}


