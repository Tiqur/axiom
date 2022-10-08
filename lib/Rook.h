struct Rook: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Rook(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Rook::getTargetedSquares()
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

  return targets;
}

