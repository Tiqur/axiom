struct ChessPiece
{
  char position;
  bool team;
  char file;
  char rank;
  char delta;
  bool onAFile;
  bool onHFile; 
  bool on1Row;
  bool on8Row;
  std::array<char, 64> board;

  // Return true if piece at p is not own piece 
  bool isNotOwnPiece(char p);

  // Validate specific piece's movement
  bool validateMove(char p, std::vector<char>& targets);

  // Check if piece is on certain team
  bool isEnemyPiece(char p);
  bool isOwnPiece(char p);

  // Check if new pos is within board's bounds
  bool isWithinBounds(char file, char rank);
  
  // Append targets for pieces that loop ( rook, bishop, queen )
  void appendTargetsLoop(std::vector<char> &targets, char fileOffset, char rankOffset);

  ChessPiece(std::array<char, 64> board, char position, bool team)
  {
    this->position = position;

    this->team = team;
    this->board = board;
    this->delta = this->position / 8;
    this->onAFile = !((this->position) % 8);
    this->onHFile = !((this->position+1) % 8);
    this->on1Row = this->position > 55;
    this->on8Row = this->position < 8;
  }
};

bool ChessPiece::isOwnPiece(char p)
{
  return this->team ? (this->board[p] >= 65 && this->board[p] <= 90) : (this->board[p] >= 97 && this->board[p] <= 122);
}

bool ChessPiece::isEnemyPiece(char p)
{
  return this->team ? (this->board[p] >= 97 && this->board[p] <= 122) : (this->board[p] >= 65 && this->board[p] <= 90);
}

bool ChessPiece::isWithinBounds(char file, char rank)
{
  // If out of bounds
  return (file >= 0 && file <= 7 && rank >= 0 && rank <= 7);
}

bool ChessPiece::isNotOwnPiece(char p)
{
  return this->team ? !(this->board[p] >= 65 && this->board[p] <= 90) : !(this->board[p] >= 97 && this->board[p] <= 122);
}

void ChessPiece::appendTargetsLoop(std::vector<char> &targets, char fileOffset, char rankOffset)
{
  for (char i = 1; i < 8; i++)
  {
    // Position to move to
    char file = this->position % 8 + fileOffset*i;
    char rank = this->position / 8 + rankOffset*i;
    char newPos = rank*8+file;

    // Break if own piece or out of bounds
    if (!this->isWithinBounds(file, rank) || this->isOwnPiece(newPos))
      break;
    
    // Push new position to targets
    targets.push_back(newPos);

    // Break if enemy piece
    if (this->isEnemyPiece(newPos))
      break;
  }
}

bool ChessPiece::validateMove(char p, std::vector<char>& targets)
{
  bool notOwnPiece = this->isNotOwnPiece(p);

  // If empty square
  if (this->board[p] == '+') {
    targets.push_back(p);
    return false;
  // If own piece
  } else if (!notOwnPiece) {
    return true;
  // If opponent's piece
  } else if (notOwnPiece) {
    targets.push_back(p);
    return true;
  }
  return false;
}

