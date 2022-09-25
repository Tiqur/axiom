#define OLC_PGE_APPLICATION
#include "./lib/olcPixelGameEngine.h"

class Axiom : public olc::PixelGameEngine
{
  private:
    // Chess board square width px
    unsigned char squareWidth;

    // Chess piece offset 
    char pieceOffset = -7;

    // White sprites
    olc::Sprite* wk = new olc::Sprite("./sprites/wk.png");
    olc::Sprite* wq = new olc::Sprite("./sprites/wq.png");
    olc::Sprite* wr = new olc::Sprite("./sprites/wr.png");
    olc::Sprite* wb = new olc::Sprite("./sprites/wb.png");
    olc::Sprite* wn = new olc::Sprite("./sprites/wn.png");
    olc::Sprite* wp = new olc::Sprite("./sprites/wp.png");

    // Black sprites
    olc::Sprite* bk = new olc::Sprite("./sprites/bk.png");
    olc::Sprite* bq = new olc::Sprite("./sprites/bq.png");
    olc::Sprite* br = new olc::Sprite("./sprites/br.png");
    olc::Sprite* bb = new olc::Sprite("./sprites/bb.png");
    olc::Sprite* bn = new olc::Sprite("./sprites/bn.png");
    olc::Sprite* bp = new olc::Sprite("./sprites/bp.png");



  public:
    // Entire board
    char board[64];

    // True = white
    bool turn = true;

    Axiom(char* FEN)
    {
      // Set app name
      sAppName = "Axiom";

      // Set game turn
      turn = turn;

      // Board index
      char index = 0;

      // Set game board
      for (int i = 0; FEN[i] != ' '; i++)
      {
        if (FEN[i] != '/')
        {
          // Fill empty squares with 0
          if (isdigit(FEN[i])) 
            // Convert FEN[i] to digit from ascii
            for (int o = 0; o<FEN[i]-48; o++)
              board[index++] = '+';
          // Assign piece to board position
          else
            board[index++] = FEN[i];
        }
      }

      // Output board to console
      for (int x = 0; x<8; x++) {
        for (int y = 0; y<8; y++)
          std::cout << ' ' << board[x*8 + y];
        std::cout << std::endl;
      }
    }

  public:
    bool OnUserCreate() override
    {
      // Set board square width
      this->squareWidth = (ScreenWidth() / 8);
      return true;
    }

    void DrawPiece(char position, olc::Sprite* sprite)
    {
      int xPos = this->pieceOffset+this->squareWidth*(position%8);
      int yPos = this->pieceOffset+this->squareWidth*(position/8);
      DrawSprite(xPos, yPos, sprite);
    }

    void DrawPieces()
    {
      // Set mode transparency (computationally intensive, so only use before drawing sprites)
      SetPixelMode(olc::Pixel::ALPHA);

      // Loop through board array
      for (int position = 0; position < 64; position++)
      {
        // Init sprite
        olc::Sprite* sprite;

        // Get correct sprite
        switch (board[position])
        {
          case 'r': // Black Rook
            sprite = this->br;
          break;
          case 'n': // Black Knight
            sprite = this->bn;
          break;
          case 'b': // Black Bishop
            sprite = this->bb;
          break;
          case 'q': // Black Queen
            sprite = this->bq;
          break;
          case 'k': // Black King
            sprite = this->bk;
          break;
          case 'p': // Black Pawn
            sprite = this->bp;
          break;
          case 'R': // White Rook
            sprite = this->wr;
          break;
          case 'N': // White Knight
            sprite = this->wn;
          break;
          case 'B': // White Bishop
            sprite = this->wb;
          break;
          case 'Q': // White Queen
            sprite = this->wq;
          break;
          case 'K': // White King
            sprite = this->wk;
          break;
          case 'P': // White Pawn
            sprite = this->wp;
          break;
          default: 
            sprite = NULL;
          break;
        }

        // Draw sprite
        if (sprite != NULL)
          DrawPiece(position, sprite);
      }

      // Disable transparency mode for performance
      SetPixelMode(olc::Pixel::NORMAL);

    }

    void DrawBoard()
    {
      // Draw board squares
      for (int x = 0; x < ScreenWidth(); x++) {
        for (int y = 0; y < ScreenHeight(); y++) {
          bool algo = (((x / this->squareWidth) % 2) && !((y / this->squareWidth) % 2)) || (!((x / this->squareWidth) % 2) && ((y / this->squareWidth) % 2));
          int r = algo ? 75 : 234;
          int g = algo ? 115 : 233;
          int b = algo ? 154 : 210;
          Draw(x, y, olc::Pixel(r, g, b));	
        }
      }
    }

    char getPositionFromCoords(int x, int y)
    {
      return (int)(x / this->squareWidth) + (int)(y / this->squareWidth) * 8;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
      // Current board position from mouse coords
      char currentPosition = getPositionFromCoords(GetMouseX(), GetMouseY());
      if (GetMouse(0).bHeld)
        std::cout << (int)currentPosition << " " << "held" << std::endl;

      // Draw Squares
      DrawBoard();

      // Draw Pieces
      DrawPieces();

      return true;
    }
};
