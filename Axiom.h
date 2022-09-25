#define OLC_PGE_APPLICATION
#include "./lib/olcPixelGameEngine.h"

class Axiom : public olc::PixelGameEngine
{
  private:
    char pixelWidth = ScreenWidth() / 8;

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
      return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
      for (int x = 0; x < ScreenWidth(); x++) {
        for (int y = 0; y < ScreenHeight(); y++) {
          bool algo = (((x / this->pixelWidth) % 2) && !((y / this->pixelWidth) % 2)) || (!((x / this->pixelWidth) % 2) && ((y / this->pixelWidth) % 2));
          int r = algo ? 75 : 234;
          int g = algo ? 115 : 233;
          int b = algo ? 154 : 210;
          Draw(x, y, olc::Pixel(r, g, b));	
        }
      }
      return true;
    }
};
