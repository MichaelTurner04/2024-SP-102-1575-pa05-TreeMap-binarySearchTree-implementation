#include "MyMap.h"
#include <ctime>
#include <map>
#include <stdlib.h>

int main() {
  time_t seed;
  srand(time(&seed));

  MyMap<std::string, int> your_map;

  int r = rand() % 50;
  your_map["a"] = r;

  your_map["a"] = r + 1;
  int test_val = your_map["a"];
}
