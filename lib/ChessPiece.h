struct ChessPiece
{
  char position;
  bool team;
  char delta;
  bool onAFile;
  bool onHFile; 
  bool on1Row;
  bool on8Row;
  char* board;

  // Return true if piece at p is not own piece 
  bool isNotOwnPiece(char p);

  // Validate specific piece's movement
  bool validateMove(char p, std::vector<char>& targets);

  ChessPiece(char* board, char position)
  {
    this->position = position;
    this->team = true;
    this->board = board;
    this->delta = this->position / 8;
    this->onAFile = !((this->position) % 8);
    this->onHFile = !((this->position+1) % 8);
    this->on1Row = this->position > 55;
    this->on8Row = this->position < 8;
  }
};


bool ChessPiece::isNotOwnPiece(char p)
{
  return this->team ? !(this->board[p] >= 65 && this->board[p] <= 90) : !(this->board[p] >= 97 && this->board[p] <= 122);
}

bool ChessPiece::validateMove(char p, std::vector<char>& targets)
{
  bool notOwnPiece = this->isNotOwnPiece(p);

  // If empty square
  if (this->board[p] == '+') {
    targets.push_back(p);
    return false;
  // If own piece
  } else if (notOwnPiece) {
    return true;
  // If opponent's piece
  } else if (!notOwnPiece) {
    targets.push_back(p);
    return true;
  }
  return false;
}

