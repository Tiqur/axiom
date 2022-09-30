struct King: public ChessPiece {
  std::vector<char> getTargetedSquares();
  King(char* board, char position) 
  : ChessPiece(board, position){}
};

std::vector<char> King::getTargetedSquares()
{
  std::vector<char> targets;


  // Diagonals ( There HAS To be a better way to do this... )
  bool tl = true;
  bool tr = true;
  bool bl = true;
  bool br = true;

  // Right
  if (!ChessPiece::onHFile) {
    if (isNotOwnPiece(ChessPiece::position+1)) targets.push_back(ChessPiece::position+1);
  } else {
    br = false;
    tr = false;
  }

  // Left
  if (!ChessPiece::onAFile){
    if (isNotOwnPiece(ChessPiece::position-1)) targets.push_back(ChessPiece::position-1);
  } else {
    bl = false;
    tl = false;
  }

  // Up
  if (!ChessPiece::on1Row) {
    if (isNotOwnPiece(ChessPiece::position+8)) targets.push_back(ChessPiece::position+8);
  } else {
    bl = false;
    br = false;
  }

  // Down 
  if (!ChessPiece::on8Row) {
    if (isNotOwnPiece(ChessPiece::position-8)) targets.push_back(ChessPiece::position-8);
  } else {
    tl = false;
    tr = false;
  }

  // Push diagonals
  if (bl && isNotOwnPiece(ChessPiece::position+7)) targets.push_back(ChessPiece::position+7);
  if (br && isNotOwnPiece(ChessPiece::position+9)) targets.push_back(ChessPiece::position+9);
  if (tl && isNotOwnPiece(ChessPiece::position-9)) targets.push_back(ChessPiece::position-9);
  if (tr && isNotOwnPiece(ChessPiece::position-7)) targets.push_back(ChessPiece::position-7);

  return targets;
}

