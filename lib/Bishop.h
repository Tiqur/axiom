struct Bishop: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Bishop(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Bishop::getTargetedSquares()
{
  std::vector<char> targets;

  // Top Right
  ChessPiece::appendTargetsLoop(targets, -7);

  // Top Left
  ChessPiece::appendTargetsLoop(targets, -9);

  // Bottom Left
  ChessPiece::appendTargetsLoop(targets, 7);

  // Bottom Right
  ChessPiece::appendTargetsLoop(targets, 9);

  return targets;
}

