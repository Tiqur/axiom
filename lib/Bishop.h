#include <vector>

struct Bishop {
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
std::vector<char> Bishop::getTargetedSquares() {
  std::vector<char> targets;

  // Top Left
  for (int i = this->position; i < this->position; i-=9)
    targets.push_back(i);

  return targets;
};
