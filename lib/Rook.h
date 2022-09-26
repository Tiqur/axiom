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

  // Row excluding current position
  for (int i = low; i < low+8; i++)
    if (i != this->position)
      targets.push_back(i);

  // File excuding current position
  for (int i = delta; i < 64; i+=8)
    if (i != this->position)
      targets.push_back(i);

  return targets;
};
