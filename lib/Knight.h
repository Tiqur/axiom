#include <vector>

struct Knight {
  private:
    char position;

    // Private Methods
    std::vector<char> getTargetedSquares();

  public:
    Knight(char position) {
      this->position = position;


      std::vector<char> targetedSquares = getTargetedSquares();

      for (char c: targetedSquares)
        std::cout << (int)c << std::endl;

    }
};


// Get all squares that the piece targets
std::vector<char> Knight::getTargetedSquares() {
  std::vector<char> targets;


  // Not on A File
  if (this->position%8) {
    // o
    // o o o
    // Not on B File or on top row
    if ((this->position-1)%8 && this->position > 7)
      targets.push_back(this->position-10);

    // o o
    //   o
    //   o
    //   Not on top two rows
    if (this->position > 15)
      targets.push_back(this->position-17);
    
    //   o
    //   o
    // o o
    // Not within bottom two rows
    if (this->position < 48)
      targets.push_back(this->position+15);

    // o o o
    // o    
    // Not on B File or bottom row
    if ((this->position-1)%8 && this->position < 56)
      targets.push_back(this->position+6);
  }

  // Not on H File
  if ((this->position+1)%8) {
    // o o
    // o  
    // o  
    //   Not on top two rows
    if (this->position > 15)
        targets.push_back(this->position-15);

    //     o
    // o o o
    // Not on G File or top row
    if ((this->position+2)%8 && this->position > 7)
      targets.push_back(this->position-6);

    // o o o
    //     o
    // Not on G File or bottom row
    if ((this->position+2)%8 && this->position < 56)
      targets.push_back(this->position+10);

    // o  
    // o  
    // o o
    // Not within bottom two rows
    if (this->position < 48)
      targets.push_back(this->position+17);
  }

  return targets;
};
