struct Bishop: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Bishop(char* board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Bishop::getTargetedSquares()
{
  std::vector<char> targets;

  // Top right
  for (char i = ChessPiece::position+1; i <= delta * 8 + 7 && i-(i-ChessPiece::position)*8 >= 0; i++)
    if (ChessPiece::validateMove(i - (i-ChessPiece::position) * 8, targets)) break;

  // Bottom right
  for (char i = ChessPiece::position+1; i <= delta * 8 + 7 && i+(i-ChessPiece::position)*8 <= 63; i++)
    if (ChessPiece::validateMove(i + (i-ChessPiece::position) * 8, targets)) break;

  // Bottom left
  for (char i = ChessPiece::position-1; i >= delta * 8 && i+(i-ChessPiece::position) * 8 >= 0; i--)
    if (ChessPiece::validateMove(i+(i-ChessPiece::position) * 8, targets)) break;

  // Bottom Top
  for (char i = ChessPiece::position-1; i >= delta * 8 && i-(i-ChessPiece::position) * 8 <= 63; i--)
    if (ChessPiece::validateMove(i-(i-ChessPiece::position) * 8, targets)) break;

  return targets;
}

