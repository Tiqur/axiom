struct Knight: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Knight(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Knight::getTargetedSquares()
{
  std::vector<char> targets;
  char toCheck[8][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};

  for (int i = 0; i < 8; i++)
  {
    char fileOffset = toCheck[i][0];
    char rankOffset = toCheck[i][1];

    char file = this->position % 8 + fileOffset;
    char rank = this->position / 8 + rankOffset;

    if (ChessPiece::isWithinBounds(file, rank) && ChessPiece::isNotOwnPiece(file+rank*8))
      targets.push_back(file+rank*8);
  }

  return targets;
}

