#define OLC_PGE_APPLICATION

#include "./olcPixelGameEngine.h"

class BoardRenderer : public olc::PixelGameEngine
{
  private:
    // Chess board square width px
    unsigned char squareWidth;

    // Chess piece offset 
    char pieceOffset = 0;

    // Last clicked square
    char clickedSquare = -1;
    char lastClickedSquare = -1;

    // Current square hovered over
    char currentMouseSquarePos;

    // Sprite scale
    float spriteScale = 0.43;

    // Board positions
    std::array<char, 64> board;

    // Custom Square Colors
    std::array<char, 64> customSquareColors = {0};

    // White Decals
    olc::Decal* wk = nullptr;
    olc::Decal* wq = nullptr;
    olc::Decal* wr = nullptr;
    olc::Decal* wb = nullptr;
    olc::Decal* wn = nullptr;
    olc::Decal* wp = nullptr;

    // Black Decals
    olc::Decal* bk = nullptr;
    olc::Decal* bq = nullptr;
    olc::Decal* br = nullptr;
    olc::Decal* bb = nullptr;
    olc::Decal* bn = nullptr;
    olc::Decal* bp = nullptr;


  public:
    // True = white
    bool turn = true;

    BoardRenderer()
    {

      // Set app name
      sAppName = "Axiom";
    }

    bool OnUserCreate() override
    {
      // Set board square width
      this->squareWidth = (ScreenWidth() / 8);

      // White Sprites -> Decals
      this->wk = new olc::Decal(new olc::Sprite("./sprites/wk.png"));
      this->wq = new olc::Decal(new olc::Sprite("./sprites/wq.png"));
      this->wr = new olc::Decal(new olc::Sprite("./sprites/wr.png"));
      this->wb = new olc::Decal(new olc::Sprite("./sprites/wb.png"));
      this->wn = new olc::Decal(new olc::Sprite("./sprites/wn.png"));
      this->wp = new olc::Decal(new olc::Sprite("./sprites/wp.png"));

      // Black Sprites -> Decals
      this->bk = new olc::Decal(new olc::Sprite("./sprites/bk.png"));
      this->bq = new olc::Decal(new olc::Sprite("./sprites/bq.png"));
      this->br = new olc::Decal(new olc::Sprite("./sprites/br.png"));
      this->bb = new olc::Decal(new olc::Sprite("./sprites/bb.png"));
      this->bn = new olc::Decal(new olc::Sprite("./sprites/bn.png"));
      this->bp = new olc::Decal(new olc::Sprite("./sprites/bp.png"));

      return true;
    }

    void DrawPiece(char position, olc::Decal* decal)
    {
      // Calculate sprite location
      int xPos = this->pieceOffset+this->squareWidth*(position%8);
      int yPos = this->pieceOffset+this->squareWidth*(position/8);
      olc::vf2d pos = { (float)xPos, (float)yPos };

      // Draw
      DrawDecal(pos, decal, {this->spriteScale, this->spriteScale});
    }

    void DrawPieces()
    {
      // Set mode transparency (computationally intensive, so only use before drawing sprites)
      //SetPixelMode(olc::Pixel::ALPHA);
      SetPixelMode(olc::Pixel::NORMAL);

      // Loop through board array
      for (int position = 0; position < 64; position++)
      {
        // Get correct sprite
        switch (this->board[position])
        {
          case 'r': // Black Rook
            DrawPiece(position, this->br);
          break;
          case 'n': // Black Knight
            DrawPiece(position, this->bn);
          break;
          case 'b': // Black Bishop
            DrawPiece(position, this->bb);
          break;
          case 'q': // Black Queen
            DrawPiece(position, this->bq);
          break;
          case 'k': // Black King
            DrawPiece(position, this->bk);
          break;
          case 'p': // Black Pawn
            DrawPiece(position, this->bp);
          break;
          case 'R': // White Rook
            DrawPiece(position, this->wr);
          break;
          case 'N': // White Knight
            DrawPiece(position, this->wn);
          break;
          case 'B': // White Bishop
            DrawPiece(position, this->wb);
          break;
          case 'Q': // White Queen
            DrawPiece(position, this->wq);
          break;
          case 'K': // White King
            DrawPiece(position, this->wk);
          break;
          case 'P': // White Pawn
            DrawPiece(position, this->wp);
          break;
        }
      }

      // Disable transparency mode for performance
      //SetPixelMode(olc::Pixel::NORMAL);
    }

    // Draw board position number on each square
    void DrawSquareNumber()
    {
      char offset = 2;
      // Loop through board array
      for (int position = 0; position < 64; position++)
      {
        int x = this->pieceOffset+this->squareWidth*(position%8);
        int y = this->pieceOffset+this->squareWidth*(position/8);
        DrawString(x+offset, y+offset, std::to_string(position), olc::RED);
      }
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

    void setBoard(std::array<char, 64> board)
    {
      this->board = board;
    }

    char getCurrentSquareHoverPos()
    {
      return this->currentMouseSquarePos;
    }

    char getLastClickedSquare()
    {
      return this->lastClickedSquare;
    }

    char getClickedSquare()
    {
      return this->clickedSquare;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
      // Current board position from mouse coords
      this->currentMouseSquarePos = getPositionFromCoords(GetMouseX(), GetMouseY());

      // Handle click events 
      static bool mouseHeld = false;
      if (GetMouse(0).bHeld)
      {
        mouseHeld = true;
      } 
      else 
      {
        if (mouseHeld)
        {
          // Swap lastClickedSquare to clickedSquare and set new clickedSquare
          this->lastClickedSquare = this->clickedSquare;
          this->clickedSquare = getPositionFromCoords(GetMouseX(), GetMouseY());
        }
        mouseHeld = false;
      }

      // Draw Squares
      DrawBoard();

      // Draw Pieces
      DrawPieces();

      // For Debug
      DrawSquareNumber();

      return true;
    }

    void setCustomSquareColors(std::array<char, 64> customSquareColors)
    {
      this->customSquareColors = customSquareColors;
    }
};
