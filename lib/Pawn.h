struct Pawn {
  private:
    char position;
    bool color;

    // Private Methods
    std::vector<char> getTargetedSquares();

  public:
    Pawn(char position, bool color) {
      this->position = position;
      this->color = color;


      std::vector<char> targetedSquares = getTargetedSquares();

      for (char c: targetedSquares)
        std::cout << (int)c << std::endl;

    }
};


// Get all squares that the piece targets
std::vector<char> Pawn::getTargetedSquares() {
  char d = this->color ? 1 : -1;
  bool onAFile = !((this->position) % 8);
  bool onHFile = !((this->position+1) % 8);
  std::vector<char> targets;
  
  // Push forward one
  targets.push_back(this->position+8*d);

  // Attack left of pawn
  if (!(d ? onAFile : onHFile)) 
    targets.push_back(this->position+7*d);

  // Attack right of pawn
  if (!(d ? onHFile : onAFile))
    targets.push_back(this->position+9*d);

  // If pawn hasn't moved
  if ((d && this->position >= 8 && this->position <= 15) || (this->position >= 48 && this->position <= 55))
    targets.push_back(this->position+16*d);

  return targets;
};
