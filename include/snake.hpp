#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <vector>

#include "utilities.hpp"

class Snake {
  private:
    Coordinates m_head{ WIDTH / 2, HEIGHT / 2 };
    char m_dir = 'u';
    std::vector<Coordinates> m_body;

  public:
    void move();
    void set_dir(char dir);
    void grow();
    [[nodiscard]] bool eaten(Coordinates food_pos) const;
    [[nodiscard]] bool collide() const;
    [[nodiscard]] Coordinates get_head() const;
    [[nodiscard]] std::vector<Coordinates> get_body() const;
};

#endif  // SNAKE_HPP_
