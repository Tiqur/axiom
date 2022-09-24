#include <vector>

struct Rook {
  private:
    char position;

    // Private Methods
    std::vector<char> getTargetedSquares();

  public:
    Rook(char position) {
      this->position = position;


      std::vector<char> targetedSquares = getTargetedSquares();

      for (char c: targetedSquares)
        std::cout << (int)c << std::endl;

    }
};


// Get all squares that the piece targets
std::vector<char> Rook::getTargetedSquares() {
  std::vector<char> targets;
  char delta = this->position % 8;
  char low = this->position - delta;

  // Left of piece
  for (int i = low; i < this->position; i++)
    targets.push_back(i);

  // Right of piece
  for (int i = this->position+1; i < low+8; i++)
    targets.push_back(i);

  // Top of piece
  for (int i = this->position-8; i > -1; i-=8)
    targets.push_back(i);

  // Bottom of piece
  for (int i = this->position+8; i < 64; i+=8)
    targets.push_back(i);

  return targets;
};
