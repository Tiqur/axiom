struct King: public ChessPiece {
  std::vector<char> getTargetedSquares();
  King(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> King::getTargetedSquares()
{
  std::vector<char> targets;

  for (char i = -1; i < 2; i++)
  {
    for (char o = -1; o < 2; o++)
    {
      if (i == 0 && o == 0) continue;
      char file = this->position % 8 + i;
      char rank = this->position / 8 + o;

      if (ChessPiece::isWithinBounds(file, rank) && ChessPiece::isNotOwnPiece(file+rank*8))
        targets.push_back(file+rank*8);
    }
  }

  return targets;
}

