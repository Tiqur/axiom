struct Pawn: public ChessPiece {
  std::vector<char> getTargetedSquares();
  Pawn(char* board, char position, bool team) 
  : ChessPiece(board, position, team){}
};

std::vector<char> Pawn::getTargetedSquares()
{
  std::vector<char> targets;
  char d = ChessPiece::team ? -1 : 1;

  // Attack left or right of pawn if opponent piece is there
  if (!(ChessPiece::team ? ChessPiece::onHFile : ChessPiece::onAFile ) && ChessPiece::isNotOwnPiece(ChessPiece::position+7*d) && ChessPiece::board[ChessPiece::position+7*d] != '+') 
    targets.push_back(ChessPiece::position+7*d);

  // Attack left or right of pawn if opponent piece is there
  if (!(ChessPiece::team ? ChessPiece::onAFile : ChessPiece::onHFile ) && ChessPiece::isNotOwnPiece(ChessPiece::position+9*d) && ChessPiece::board[ChessPiece::position+9*d] != '+')
    targets.push_back(ChessPiece::position+9*d);

  // Push forward one if nothing in front
  if (ChessPiece::board[ChessPiece::position+8*d] == '+')
    targets.push_back(ChessPiece::position+8*d);

  // If pawn hasn't moved push forward if nothing in front
  if ((ChessPiece::team ? (ChessPiece::position >= 48 && ChessPiece::position <= 55) : (ChessPiece::position >= 8 && ChessPiece::position <= 15)) && ChessPiece::board[ChessPiece::position+16*d] == '+' && ChessPiece::board[ChessPiece::position+8*d] == '+')
    targets.push_back(ChessPiece::position+16*d);

  return targets;
}

