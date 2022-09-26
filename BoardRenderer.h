#define OLC_PGE_APPLICATION
#include "./lib/olcPixelGameEngine.h"

class BoardRenderer : public olc::PixelGameEngine
{
  private:
    // Chess board square width px
    unsigned char squareWidth;

    // Chess piece offset 
    char pieceOffset = -7;

    // Board positions
    char *board;

    // Custom Square Colors
    char customSquareColors[64] = {0};

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
    // True = white
    bool turn = true;

    BoardRenderer(char board[64])
    {
      // Set board positions
      this->board = board;

      // Set app name
      sAppName = "Axiom";
    }

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
        switch (this->board[position])
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
          // Color only correct squares
          bool algo = (((x / this->squareWidth) % 2) && !((y / this->squareWidth) % 2)) || (!((x / this->squareWidth) % 2) && ((y / this->squareWidth) % 2));

          // Current position on board
          char position = getPositionFromCoords(x, y);

          // Get square color at current position
          char customColor = customSquareColors[position];

          // Colors for square
          int r;
          int g;
          int b;

          // Set default color
          if (!customSquareColors[position]) {
            r = algo ? 75 : 234;
            g = algo ? 115 : 233;
            b = algo ? 154 : 210;
          } else {
            // Set custom color
            switch (customColor)
            {
              case 'r': // Red
                r = algo ? 203 : 234;
                g = algo ? 100 : 124;
                b = algo ? 94 : 105;
              break;
              case 'g': // Green
                r = algo ? 152 : 184;
                g = algo ? 187 : 211;
                b = algo ? 101 : 113;
              break;
              case 'b': // Blue
                r = algo ? 80 : 112;
                g = algo ? 163 : 187;
                b = algo ? 206 : 218;
              break;
              case 'o': // Orange
                r = algo ? 219 : 250;
                g = algo ? 159 : 182;
                b = algo ? 30 : 41;
              break;
            }
          }

          // Draw pixel
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
      //char currentPosition = getPositionFromCoords(GetMouseX(), GetMouseY());
      //if (GetMouse(0).bHeld)
        //customSquareColors[currentPosition] = 'r';

      customSquareColors[0] = 'r';
      customSquareColors[1] = 'r';
      customSquareColors[8] = 'g';
      customSquareColors[9] = 'g';
      customSquareColors[16] = 'b';
      customSquareColors[17] = 'b';
      customSquareColors[24] = 'o';
      customSquareColors[25] = 'o';


      // Draw Squares
      DrawBoard();

      // Draw Pieces
      DrawPieces();

      return true;
    }
};
