#include <iostream>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./BoardRenderer.h"

void parseFEN(char* FEN, char* board, bool turn, bool& ck, bool& cq, bool& cK, bool& cQ)
{
  // Fen Index 
  char fenIndex = 0;




  // Board index
  char boardIndex = 0;

  // Set game board
  for (fenIndex; FEN[fenIndex] != ' '; fenIndex++)
  {
    if (FEN[fenIndex] != '/')
    {
      // Fill empty squares with 0
      if (isdigit(FEN[fenIndex])) 
        // Convert FEN[i] to digit from ascii
        for (int o = 0; o<FEN[fenIndex]-48; o++)
          board[boardIndex++] = '+';
      // Assign piece to board position
      else
        board[boardIndex++] = FEN[fenIndex];
    }
  }




  // Set Turn ( true -> white   false -> black )
  for (fenIndex++; FEN[fenIndex] != ' '; fenIndex++)
    turn = FEN[fenIndex] == 'w';



  
  // Castling Rights
  for (fenIndex++; FEN[fenIndex] != ' '; fenIndex++)
  {
    switch(FEN[fenIndex])
    {
      case 'q':
        ck = true;
      break;
      case 'k':
        cq = true;
      break;
      case 'Q':
        cK = true;
      break;
      case 'K':
        cQ = true;
      break;
    }
  }



};


int main() {
    char FEN[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << FEN << std::endl;

    // Holds all positions on board
    char board[64];

    // Turn (true for white)
    bool turn;

    // Castling rights
    bool ck = false;
    bool cq = false;
    bool cK = false;
    bool cQ = false; 

    // Parse FEN into board positions
    parseFEN(FEN, board, turn, ck, cq, cK, cQ);

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


