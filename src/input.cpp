#include "../include/input.hpp"

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

int kbhit() {
  termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
  int bytes_waiting = 0;
  ioctl(STDIN_FILENO, FIONREAD, &bytes_waiting);
  return bytes_waiting;
}
