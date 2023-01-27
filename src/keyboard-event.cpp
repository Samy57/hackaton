#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdio>
#include <ctime>

static const int STDIN = 0;
static bool initialized = false;

void backgroundClear() {
  int out = system("clear");
  if (out != 0) {
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}
