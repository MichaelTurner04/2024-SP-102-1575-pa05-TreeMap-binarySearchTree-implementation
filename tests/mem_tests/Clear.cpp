#include "MyMap.h"
#include <ctime>
#include <map>
#include <stdlib.h>

int main() {
  time_t seed;
  srand(time(&seed));

  std::map<std::string, int> test_map;
  MyMap<std::string, int> your_map;

  your_map.begin() = new TreeNode<std::string, int>(
      "t", 1, new TreeNode<std::string, int>("j", 2),
      new TreeNode<std::string, int>("x", 3));

  your_map.clear();
}
