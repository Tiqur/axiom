struct King {
  private:
    char position;

    // Private Methods
    std::vector<char> getTargetedSquares();

  public:
    King(char position) {
      this->position = position;


      std::vector<char> targetedSquares = getTargetedSquares();

      for (char c: targetedSquares)
        std::cout << (int)c << std::endl;

    }
};


// Get all squares that the piece targets
std::vector<char> King::getTargetedSquares() {


  // Push forward one
  bool onAFile = !((this->position) % 8);
  bool onHFile = !((this->position+1) % 8);
  bool on1Row = this->position > 55;
  bool on8Row = this->position < 8;

  // Diagonals ( There HAS To be a better way to do this... )
  bool tl = true;
  bool tr = true;
  bool bl = true;
  bool br = true;

  std::vector<char> targets;

  // Right
  if (!onHFile) {
    targets.push_back(this->position+1);
  } else {
    br = false;
    tr = false;
  }

  // Left
  if (!onAFile){
    targets.push_back(this->position-1);
  } else {
    bl = false;
    tl = false;
  }

  // Up
  if (!on1Row) {
    targets.push_back(this->position+8);
  } else {
    bl = false;
    br = false;
  }

  // Down 
  if (!on8Row) {
    targets.push_back(this->position-8);
  } else {
    tl = false;
    tr = false;
  }

  // Push diagonals
  if (bl) targets.push_back(this->position+7);
  if (br) targets.push_back(this->position+9);
  if (tl) targets.push_back(this->position-9);
  if (tr) targets.push_back(this->position-7);


  return targets;
};
