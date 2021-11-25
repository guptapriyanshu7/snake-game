#include "../include/food.hpp"

void Food::gen_food() {
  m_pos.x = rand() % (WIDTH - 2) + 1;
  m_pos.y = rand() % (HEIGHT - 2) + 1;
}

Coordinates Food::get_pos() const { return m_pos; }
