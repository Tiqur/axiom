struct Queen: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Queen(char* board, char position) 
  : ChessPiece(board, position){}
};

std::vector<char> Queen::getTargetedSquares()
{
  std::vector<char> targets;

  // Left
  for(char i=ChessPiece::position-1; i>ChessPiece::delta*8-1; i--)
    if (ChessPiece::validateMove(i, targets)) break;

  // Right
  for(char i=ChessPiece::position+1; i<ChessPiece::delta*8+8; i++)
    if (ChessPiece::validateMove(i, targets)) break;

  // Up
  for(char i=ChessPiece::position-8; i>ChessPiece::position-ChessPiece::delta*8-8; i-=8)
    if (ChessPiece::validateMove(i, targets)) break;

  // Down
  for(char i=ChessPiece::position+8; i<ChessPiece::position+(8-ChessPiece::delta)*8; i+=8)
    if (ChessPiece::validateMove(i, targets)) break;

  // Top right
  for (char i = ChessPiece::position+1; i <= ChessPiece::delta * 8 + 7 && i-(i-ChessPiece::position)*8 >= 0; i++)
    if (ChessPiece::validateMove(i - (i-ChessPiece::position) * 8, targets)) break;

  // Bottom right
  for (char i = ChessPiece::position+1; i <= ChessPiece::delta * 8 + 7 && i+(i-ChessPiece::position)*8 <= 63; i++)
    if (ChessPiece::validateMove(i + (i-ChessPiece::position) * 8, targets)) break;

  // Bottom left
  for (char i = ChessPiece::position-1; i >= ChessPiece::delta * 8 && i+(i-ChessPiece::position) * 8 >= 0; i--)
    if (ChessPiece::validateMove(i+(i-ChessPiece::position) * 8, targets)) break;

  // Bottom Top
  for (char i = ChessPiece::position-1; i >= ChessPiece::delta * 8 && i-(i-ChessPiece::position) * 8 <= 63; i--)
    if (ChessPiece::validateMove(i-(i-ChessPiece::position) * 8, targets)) break;

  return targets;
}

