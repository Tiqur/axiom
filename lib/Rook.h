struct Rook: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Rook(char* board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Rook::getTargetedSquares()
{
  std::vector<char> targets;

  // Left
  for(char i=ChessPiece::position-1; i>delta*8-1; i--)
    if (ChessPiece::validateMove(i, targets)) break;

  // Right
  for(char i=ChessPiece::position+1; i<delta*8+8; i++)
    if (ChessPiece::validateMove(i, targets)) break;

  // Up
  for(char i=ChessPiece::position-8; i>ChessPiece::position-delta*8-8; i-=8)
    if (ChessPiece::validateMove(i, targets)) break;

  // Down
  for(char i=ChessPiece::position+8; i<ChessPiece::position+(8-delta)*8; i+=8)
    if (ChessPiece::validateMove(i, targets)) break;

  return targets;
}

