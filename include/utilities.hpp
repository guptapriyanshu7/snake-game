#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#define WIDTH  50
#define HEIGHT 25

struct Coordinates {
    int x;
    int y;
    bool operator==(const Coordinates& other) const {
      return x == other.x && y == other.y;
    }
};

#endif  // UTILITIES_HPP_
