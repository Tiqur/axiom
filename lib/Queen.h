struct Queen: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Queen(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Queen::getTargetedSquares()
{
  std::vector<char> targets;

  // Left
  ChessPiece::appendTargetsLoop(targets, -1);

  // Right
  ChessPiece::appendTargetsLoop(targets, 1);

  // up
  ChessPiece::appendTargetsLoop(targets, -8);

  // Down
  ChessPiece::appendTargetsLoop(targets, 8);

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

