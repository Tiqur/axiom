struct Knight: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Knight(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Knight::getTargetedSquares()
{
  std::vector<char> targets;

  // Not on A File
  if (ChessPiece::position%8) {
    // o
    // o o o
    // Not on B File or on top row
    if ((ChessPiece::position-1)%8 && ChessPiece::position > 7)
      if (isNotOwnPiece(ChessPiece::position-10)) targets.push_back(ChessPiece::position-10);

    // o o
    //   o
    //   o
    //   Not on top two rows
    if (ChessPiece::position > 15)
      if (isNotOwnPiece(ChessPiece::position-17)) targets.push_back(ChessPiece::position-17);
    
    //   o
    //   o
    // o o
    // Not within bottom two rows
    if (ChessPiece::position < 48)
      if (isNotOwnPiece(ChessPiece::position+15)) targets.push_back(ChessPiece::position+15);

    // o o o
    // o    
    // Not on B File or bottom row
    if ((ChessPiece::position-1)%8 && ChessPiece::position < 56)
      if (isNotOwnPiece(ChessPiece::position+6)) targets.push_back(ChessPiece::position+6);
  }

  // Not on H File
  if ((ChessPiece::position+1)%8) {
    // o o
    // o  
    // o  
    //   Not on top two rows
    if (ChessPiece::position > 15)
        if (isNotOwnPiece(ChessPiece::position-15)) targets.push_back(ChessPiece::position-15);

    //     o
    // o o o
    // Not on G File or top row
    if ((ChessPiece::position+2)%8 && ChessPiece::position > 7)
      if (isNotOwnPiece(ChessPiece::position-6)) targets.push_back(ChessPiece::position-6);

    // o o o
    //     o
    // Not on G File or bottom row
    if ((ChessPiece::position+2)%8 && ChessPiece::position < 56)
      if (isNotOwnPiece(ChessPiece::position+10)) targets.push_back(ChessPiece::position+10);

    // o  
    // o  
    // o o
    // Not within bottom two rows
    if (ChessPiece::position < 48)
      if (isNotOwnPiece(ChessPiece::position+17)) targets.push_back(ChessPiece::position+17);
  }
  return targets;
}

