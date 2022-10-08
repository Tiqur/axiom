struct Rook: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Rook(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Rook::getTargetedSquares()
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

  return targets;
}

