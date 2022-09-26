#include <iostream>
#include <string>
#include <vector>
#include "./lib/Pawn.h"
#include "./lib/King.h"
#include "./lib/Rook.h"
#include "./lib/Bishop.h"
#include "./lib/Queen.h"
#include "./lib/Knight.h"
#include "./BoardRenderer.h"

void parseFEN(std::string FEN, char* board, bool turn, bool& ck, bool& cq, bool& cK, bool& cQ)
{

  std::vector<std::string> slices;
  std::stringstream ss(FEN);
  std::string segment;

  while (getline (ss, segment, ' '))
    slices.push_back(segment);



  // Set game board
  char boardIndex = 0;
  for (char& c : slices[0])
  {
    if (c != '/')
    {
      // Fill empty squares with 0
      if (isdigit(c)) 
        // Convert FEN[i] to digit from ascii
        for (int o = 0; o<c-48; o++)
          board[boardIndex++] = '+';
      // Assign piece to board position
      else
        board[boardIndex++] = c;
    }
  }

  //Output board to console
  for (int x = 0; x<8; x++) {
    for (int y = 0; y<8; y++)
      std::cout << ' ' << board[x*8 + y];
    std::cout << std::endl;
  }

  // Set Turn ( true -> white   false -> black )
  for (char& c : slices[1])
    turn = c == 'w';




  // Castling Rights
  for (char& c : slices[2])
  {
    switch(c)
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

  // ** DO THIS LATER **
  // Parse En-Passants 
  for (char& c : slices[3])
  {

  }



  // Parse Half Move Clock
  std::cout << std::stoi(slices[4]) << std::endl;
};


int main() {
  std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 100 1";
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


