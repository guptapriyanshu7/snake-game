/* Snake movement

- - 0(H) o(2) o(1) - - -

- 0 o(H) o(2) o(1) - - -  (Basically, add a 'o' at prev head pos) Line 23

- 0 o(H) o(2) - - - -  (Now, delete the last 'o', magic!) Line 24

*/

#include "../include/snake.hpp"

Coordinates Snake::get_head() const { return m_head; }

std::vector<Coordinates> Snake::get_body() const { return m_body; }

void Snake::set_dir(char dir) { m_dir = dir; }

// Same logic as move, just dont't erase
void Snake::grow() { m_body.push_back(m_head); }

void Snake::move() {
  m_body.push_back(m_head);
  m_body.erase(m_body.begin());

  switch (m_dir) {
    case 'u':
      m_head.y--;
      break;
    case 'r':
      m_head.x++;
      break;
    case 'd':
      m_head.y++;
      break;
    case 'l':
      m_head.x--;
      break;
    default:
      break;
  }
}

bool Snake::collide() const {
  for (auto&& i: m_body) {
    if (m_head.x == i.x && m_head.y == i.y)
      return true;
  }
  return m_head.x == 0 || m_head.x == WIDTH - 1
         || m_head.y == 0 || m_head.y == HEIGHT - 1;
}

bool Snake::eaten(Coordinates food_pos) const {
  return m_head.x == food_pos.x && m_head.y == food_pos.y;
}
