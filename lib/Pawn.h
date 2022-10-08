struct Pawn: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Pawn(std::array<char, 64> board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Pawn::getTargetedSquares()
{
  std::vector<char> targets;
  char d = ChessPiece::team ? -1 : 1;
  char file = this->position % 8;
  char rank = this->position / 8;

  // Attack left or right of pawn if opponent piece is there
  if (ChessPiece::isWithinBounds(file+1, rank+d) && ChessPiece::isEnemyPiece(file+1+(rank+d)*8)) 
    targets.push_back(file+1+(rank+d)*8);

  // Attack left or right of pawn if opponent piece is there
  if (ChessPiece::isWithinBounds(file-1, rank+d) && ChessPiece::isEnemyPiece(file-1+(rank+d)*8))
    targets.push_back(file-1+(rank+d)*8);

  // Push forward one if nothing in front
  if (ChessPiece::board[ChessPiece::position+8*d] == '+')
    targets.push_back(ChessPiece::position+8*d);

  // If pawn hasn't moved push forward if nothing in front
  if ((ChessPiece::team ? (ChessPiece::position >= 48 && ChessPiece::position <= 55) : (ChessPiece::position >= 8 && ChessPiece::position <= 15)) && ChessPiece::board[ChessPiece::position+16*d] == '+' && ChessPiece::board[ChessPiece::position+8*d] == '+')
    targets.push_back(ChessPiece::position+16*d);

  return targets;
}

