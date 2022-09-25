#define OLC_PGE_APPLICATION
#include <iostream>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./lib/olcPixelGameEngine.h"

class Axiom : public olc::PixelGameEngine
{
  public:
    // Entire board
    char board[64];

    // True = white
    bool turn = true;

    Axiom(char* FEN)
    {
      // Set app name
      sAppName = "Axiom";

      // Set game turn
      turn = turn;

      // Set game board
      //for (int i = 0; FEN[i] != ' '; i++)
      //{
      //  std::cout << FEN[i] << std::endl;
      //}
    }

  public:
    bool OnUserCreate() override
    {
      return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
      return true;
    }
};


int main() {
    char startingPosition[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << startingPosition << std::endl;

    Axiom game = Axiom(startingPosition);
    if (game.Construct(512, 480, 2, 2))
      game.Start();

    //Pawn pawn = Pawn(8, true);
    //King king = King(18);
    //Rook rook = Rook(60);
    //Bishop bishop = Bishop(36);
    //Queen queen = Queen(36);
    //Knight knight = Knight(52);

    return 0;
}


