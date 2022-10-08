struct Queen: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Queen(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Queen::getTargetedSquares()
{
  std::vector<char> targets;

  // Left
  ChessPiece::appendTargetsLoop(targets, -1, 0);

  // Right
  ChessPiece::appendTargetsLoop(targets, 1, 0);

  // up
  ChessPiece::appendTargetsLoop(targets, 0, -1);

  // Down
  ChessPiece::appendTargetsLoop(targets, 0, 1);

  // Top Left
  ChessPiece::appendTargetsLoop(targets, -1, -1);

  // Top Right
  ChessPiece::appendTargetsLoop(targets, 1, -1);

  // Bottom Left
  ChessPiece::appendTargetsLoop(targets, -1, 1);

  // Bottom Right
  ChessPiece::appendTargetsLoop(targets, 1, 1);


  return targets;
}

