#define OLC_PGE_APPLICATION
#include "./lib/olcPixelGameEngine.h"

class Axiom : public olc::PixelGameEngine
{
  private:
    unsigned char squareWidth;
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

      // Set game board
      //for (int i = 0; FEN[i] != ' '; i++)
      //{
      //  std::cout << FEN[i] << std::endl;
      //}
    }

  public:
    bool OnUserCreate() override
    {
      // Set board square width
      this->squareWidth = (ScreenWidth() / 8);
      return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
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

      // Set mode transparency (computationally intensive, so only use before drawing sprites)
      SetPixelMode(olc::Pixel::ALPHA);
      // Draw sprite
      DrawSprite(0, 0, this->bn);
      // Disable transparency mode for performance
      SetPixelMode(olc::Pixel::NORMAL);

      return true;
    }
};
