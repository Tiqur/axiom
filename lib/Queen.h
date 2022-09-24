#include <vector>


struct Queen {
  private:
    char position;

    // Private Methods
    std::vector<char> getTargetedSquares();

  public:
    Queen(char position) {
      this->position = position;


      std::vector<char> targetedSquares = getTargetedSquares();

      for (char c: targetedSquares)
        std::cout << (int)c << std::endl;

    }
};


// Get all squares that the piece targets
std::vector<char> Queen::getTargetedSquares() {
  std::vector<char> targets;
  char delta = this->position % 8;
  char low = this->position - delta;

  // Get nearest border
  char squaresFromLeft = this->position-low;
  char squaresFromRight = 7 - squaresFromLeft;
  char squaresFromTop = this->position/8;
  char squaresFromBottom = 7 - squaresFromTop;
  char nearestBorder;
  char startingPos;
  bool start = true;


  // Row excluding current position
  for (int i = low; i < low+8; i++)
    if (i != this->position)
      targets.push_back(i);

  // File excuding current position
  for (int i = delta; i < 64; i+=8)
    if (i != this->position)
      targets.push_back(i);


  // Starting position to iterate and find diagonal ( top left to bottom right )
  nearestBorder = squaresFromTop < squaresFromLeft ? squaresFromTop : squaresFromLeft;
  startingPos = this->position-nearestBorder-8*nearestBorder;
  for (int i = startingPos; i < 64; i+=9) {
    if (!(i % 8) && !start) break;
    start = false;
    if (i != this->position)
      targets.push_back(i);
  }


  // Starting position to iterate and find diagonal ( bottom left to top right )
  nearestBorder = squaresFromBottom < squaresFromLeft ? squaresFromBottom : squaresFromLeft;
  startingPos = this->position-nearestBorder+8*nearestBorder;
  for (int i = startingPos; i > 0; i-=7) {
    if (!(i % 8) && start) break;
    start = true;
    if (i != this->position)
      targets.push_back(i);
  }



  return targets;
};
