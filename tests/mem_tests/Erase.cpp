#include "MyMap.h"
#include <ctime>
#include <map>
#include <stdlib.h>

int main() {
  time_t seed;
  srand(time(&seed));

  MyMap<std::string, int> your_map;

  your_map.begin() = new TreeNode<std::string, int>(
      "t", 1, new TreeNode<std::string, int>("j", 2),
      new TreeNode<std::string, int>("x", 3));

  // erase ignores unfound keys

  your_map.erase("v");

  // erase properly removes valid keys
  your_map.erase("x");
}
