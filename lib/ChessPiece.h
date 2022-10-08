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
  bool isWithinBounds(char newPos);
  
  // Append targets for pieces that loop ( rook, bishop, queen )
  void appendTargetsLoop(std::vector<char>& targets, char offset);

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

bool ChessPiece::isWithinBounds(char p)
{
  char file = p % 8;
  char rank = p / 8;

  // If out of bounds
  if (file >= 7 || file <= 0 || rank >= 7 || rank <= 0)
    return false;

  return true;
}

bool ChessPiece::isNotOwnPiece(char p)
{
  return this->team ? !(this->board[p] >= 65 && this->board[p] <= 90) : !(this->board[p] >= 97 && this->board[p] <= 122);
}

void ChessPiece::appendTargetsLoop(std::vector<char> &targets, char offset)
{
  for (char i = 1; i < 8; i++)
  {
    // Position to move to
    char newPos = this->position+offset*i;

    // Break if own piece
    if (this->isOwnPiece(newPos))
      break;
    
    // Push new position to targets
    targets.push_back(newPos);

    // Break if out of bounds or enemy piece
    if (!this->isWithinBounds(newPos) || this->isEnemyPiece(newPos))
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

