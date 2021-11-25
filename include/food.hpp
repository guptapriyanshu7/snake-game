#ifndef FOOD_HPP_
#define FOOD_HPP_

#include <cstdlib>

#include "utilities.hpp"

class Food {
  private:
    Coordinates m_pos{ rand() % (WIDTH - 2) + 1,
                       rand() % (HEIGHT - 2) + 1 };

  public:
    void gen_food();
    [[nodiscard]] Coordinates get_pos() const;
};

#endif  // FOOD_HPP_
