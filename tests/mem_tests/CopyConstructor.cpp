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

  MyMap<std::string, int> other_map = your_map;

  std::vector<int> test_vect;
  std::vector<int> other_vect;
  your_map.convert_to_sorted_list(your_map.begin(), test_vect);
  other_map.convert_to_sorted_list(other_map.begin(), other_vect);

  // deep copy test
  your_map.begin()->value = 4;
}
