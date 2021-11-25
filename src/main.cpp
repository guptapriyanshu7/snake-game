#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/food.hpp"
#include "../include/input.hpp"
#include "../include/snake.hpp"

void draw(const Snake& snake, const Food& food, int score) {
  system("clear");
  std::cout << "SCORE: " << score << "\n\n";

  Coordinates food_pos                = food.get_pos();
  Coordinates snake_pos               = snake.get_head();
  std::vector<Coordinates> snake_body = snake.get_body();

  for (int i = 0; i < HEIGHT; i++) {
    std::cout << "\t\t#";
    for (int j = 1; j < WIDTH - 1; j++) {
      if (i == 0 || i == HEIGHT - 1)
        std::cout << '#';
      else if (snake_pos.x == j && snake_pos.y == i)
        std::cout << '0';
      else if (food_pos.x == j && food_pos.y == i)
        std::cout << '@';
      else if (std::find(snake_body.begin(), snake_body.end(),
                         Coordinates{ j, i })
               != snake_body.end())
        std::cout << 'o';
      else
        std::cout << ' ';
    }
    std::cout << '#' << std::endl;
  }
}

int main() {
  srand(time(nullptr));

  Snake snake{};
  Food food{};

  int score = 0;

  while (true) {
    draw(snake, food, score);

    if (kbhit()) {
      switch (getchar()) {
        case 'w':
          snake.set_dir('u');
          break;
        case 'd':
          snake.set_dir('r');
          break;
        case 's':
          snake.set_dir('d');
          break;
        case 'a':
          snake.set_dir('l');
          break;
        default:
          break;
      }
    }

    if (snake.collide()) break;
    if (snake.eaten(food.get_pos())) {
      snake.grow();
      food.gen_food();
      score += 10;
    }
    snake.move();

    usleep(100000);
  }
  return 0;
}
