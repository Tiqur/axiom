struct Rook: public ChessPiece {
  Rook(char* board, char position) 
  : ChessPiece(board, position){}
};

std::vector<char> ChessPiece::getTargetedSquares()
{

  // Left
  for(char i=ChessPiece::position-1; i>delta*8-1; i--)
    if (ChessPiece::validateMove(i)) break;

  // Right
  for(char i=ChessPiece::position+1; i<delta*8+8; i++)
    if (ChessPiece::validateMove(i)) break;

  // Up
  for(char i=ChessPiece::position-8; i>ChessPiece::position-delta*8-8; i-=8)
    if (ChessPiece::validateMove(i)) break;

  // Down
  for(char i=ChessPiece::position+8; i<ChessPiece::position+(8-delta)*8; i+=8)
    if (ChessPiece::validateMove(i)) break;

  return ChessPiece::targets;
}

