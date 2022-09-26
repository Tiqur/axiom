// Holds all states and positions for current FEN
struct Game 
{
  // Holds all positions on board
  char board[64];

  // Turn (true for white)
  bool turn;

  // Castling rights
  bool ck;
  bool cq;
  bool cK;
  bool cQ; 

  // Half move clock
  char halfMoveClock;

  // Full Move Counter
  char fullMoveCounter;

  Game(std::string FEN)
  {
    // Split FEN into chunks
    std::vector<std::string> slices;
    std::stringstream ss(FEN);
    std::string segment;

    // Push chunks to slices vector
    while (getline (ss, segment, ' '))
      slices.push_back(segment);

    // Parse game states
    parseBoard(slices[0]);
    parseTurn(slices[1]);
    parseCastlingRights(slices[2]);
    parseEnPassantTargets(slices[3]);
    parseHalfMoveClock(slices[4]);
    parseFullMoveCounter(slices[5]);
    outputCurrentBoard();
  }

  // Parse and set game board
  void parseBoard(std::string slice)
  {
    char boardIndex = 0;
    for (char& c : slice)
    {
      if (c != '/')
      {
        // Fill empty squares with 0
        if (isdigit(c)) 
          // Convert FEN[i] to digit from ascii
          for (int o = 0; o<c-48; o++)
            this->board[boardIndex++] = '+';
        // Assign piece to board position
        else
          this->board[boardIndex++] = c;
      }
    }
  }
  
  // Parse Turn ( true -> white   false -> black )
  void parseTurn(std::string slice)
  {
    turn = slice[0] == 'w';
  }

  // Parse Castling Rights
  void parseCastlingRights(std::string slice)
  {
    for (char& c : slice)
    {
      switch(c)
      {
        case 'q':
          this->ck = true;
        break;
        case 'k':
          this->cq = true;
        break;
        case 'Q':
          this->cK = true;
        break;
        case 'K':
          this->cQ = true;
        break;
      }
    }
  }

  // Parse En Passant Targets
  void parseEnPassantTargets(std::string slice)
  {
    // ** DO THIS LATER **
    // Parse En-Passants 
    for (char& c : slice)
    {

    }
  }

  // Parse Half Move Clock
  void parseHalfMoveClock(std::string slice)
  {
    halfMoveClock = std::stoi(slice);
  }

  // Parse Full Move Counter
  void parseFullMoveCounter(std::string slice)
  {
    fullMoveCounter = std::stoi(slice);
  }

  // Output board to console
  void outputCurrentBoard()
  {
    for (int x = 0; x<8; x++) {
      for (int y = 0; y<8; y++)
        std::cout << ' ' << this->board[x*8 + y];
      std::cout << std::endl;
    }
  }
};
