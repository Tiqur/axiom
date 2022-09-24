#include <iostream>


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
    for (int i = 0; FEN[i] != ' '; i++)
    {
      std::cout << FEN[i] << std::endl;
    }
  }


  
};


int main() {
    char startingPosition[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << startingPosition;


    Game game = Game(startingPosition, true);

    return 0;
}


