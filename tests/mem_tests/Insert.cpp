#include "MyMap.h"
#include <ctime>
#include <map>
#include <stdlib.h>
#include <vector>

int main() {
  time_t seed;
  srand(time(&seed));

  std::map<std::string, int> test_map;
  MyMap<std::string, int> your_map;

  int r[4]{rand() % 50, rand() % 50, rand() % 50, rand() % 50};

  your_map.insert("t", r[0]);
  your_map.insert("x", r[1]);
  your_map.insert("v", r[2]);
  your_map.insert("j", r[3]);

  test_map.insert({"t", r[0]});
  test_map.insert({"x", r[1]});
  test_map.insert({"v", r[2]});
  test_map.insert({"j", r[3]});

  std::vector<int> test_vect;
  your_map.convert_to_sorted_list(your_map.begin(), test_vect);

  your_map.insert("j", 42);
}
