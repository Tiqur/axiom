#include "BoardRenderer.h"


// Holds all states and positions for current FEN
class Game 
{
  private:

    // Init board renderer
    BoardRenderer* renderer = nullptr;

    // Holds all positions on board
    char board[64];

    // Holds all possible moves
    std::unordered_map<char, std::vector<char>> possibleMoves;

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

    // Calculate possible moves and insert them into map
    void calculateAllPossibleMoves()
    {

      // Loop through board array
      for (int position = 0; position < 64; position++)
      {
        switch (this->board[position])
        {
          case 'R': // Rook
          case 'r':
            this->possibleMoves.insert({position, Rook(this->board, position).getTargetedSquares()});
          break;
          case 'N': // Knight
          case 'n':
            this->possibleMoves.insert({position, Knight(this->board, position).getTargetedSquares()});
          break;
          case 'B': // Bishop
          case 'b':
            this->possibleMoves.insert({position, Bishop(this->board, position).getTargetedSquares()});
          break;
          case 'Q': // Queen
          case 'q':
            this->possibleMoves.insert({position, Queen(this->board, position).getTargetedSquares()});
          break;
          case 'K': // King
          case 'k':
            this->possibleMoves.insert({position, King(this->board, position).getTargetedSquares()});
          break;
          case 'P': // Pawn
          case 'p':
            this->possibleMoves.insert({position, Pawn(this->board, position).getTargetedSquares()});
          break;
        }
      }
    }

  public:
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

      // Calculate possible moves for given board
      calculateAllPossibleMoves();

    for (auto & kvp : this->possibleMoves)
    {
      std::cout << (int)kvp.first << ": [";
      for (auto & a : kvp.second)
        std::cout << (int)a << ",";
      std::cout << "]" << std::endl;
    }

      // Init renderer
      this->renderer = new BoardRenderer(this->board);
    };

    // Render current board
    void render()
    {
      // Start renderer
      if (renderer->Construct(128, 128, 1, 1))
        renderer->Start();
    }

    // Getters ( self explanatory )
    char* getBoard()
    {
      return this->board;
    };
    
    bool getTurn()
    {
      return this->turn;
    };

    bool getWhiteCanCastleKingSide()
    {
      return this->cK;
    };

    bool getBlackCanCastleKingSide()
    {
      return this->ck;
    };

    bool getWhiteCanCastleQueenSide()
    {
      return this->cQ;
    };

    bool getBlackCanCastleQueenSide()
    {
      return this->cq;
    };

    int getHalfMoveClock()
    {
      return (int)this->halfMoveClock;
    };

    int getFullMoveCounter()
    {
      return (int)this->fullMoveCounter;
    };

    // Return FEN of current game states
    std::string currentBoardToFEN()
    {
      // New FEN string to return
      std::string newFEN = "";
      
      // Append each position to FEN
      for (int i = 0; i < 64; i++)
      {
        char piece = this->board[i];

        if (piece == '+')
          if ((int)newFEN.back() > 47 && (int)newFEN.back() < 57)
            newFEN[newFEN.size() - 1]++;
          else
            newFEN += '1';
        else 
          newFEN += piece;

        // Append '/' every new row
        if (!((i+1) % 8) && i != 63)
          newFEN += '/';
      }


      // Append turn to FEN
      newFEN += ' ';
      newFEN += this->turn ? 'w' : 'b';

      // Append Castling rights
      newFEN += ' ';
      if (this->ck) newFEN += 'k';
      if (this->cq) newFEN += 'q';
      if (this->cK) newFEN += 'K';
      if (this->cQ) newFEN += 'Q';

      // ** DO THIS LATER **
      // Append En Passant
      newFEN += ' ';
      newFEN += '-';

      // Append half move clock
      newFEN += ' ';
      newFEN += std::to_string(this->halfMoveClock);

      // Append full move counter
      newFEN += ' ';
      newFEN += std::to_string(this->fullMoveCounter);

      return newFEN;
    }

    // Output board to console
    void outputCurrentBoard()
    {
      for (int x = 0; x<8; x++) {
        for (int y = 0; y<8; y++)
          std::cout << ' ' << this->board[x*8 + y];
        std::cout << std::endl;
      }
    };

    // Pass square from game to BoardRenderer
    void selectSquare(char position)
    {
      this->renderer->setCustomSquareColor(position, 'b');
    }
};
