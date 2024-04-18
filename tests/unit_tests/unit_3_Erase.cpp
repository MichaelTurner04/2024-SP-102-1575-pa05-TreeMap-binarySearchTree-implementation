#include "MyMap.h"
#include "test_utils.hpp"
#include <ctime>
#include <map>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    std::map<std::string, int> test_map;
    MyMap<std::string, int> your_map;

    your_map.begin() = new TreeNode<std::string, int>(
        "t", 1, new TreeNode<std::string, int>("j", 2),
        new TreeNode<std::string, int>("x", 3));

    // erase ignores unfound keys

    your_map.erase("v");
    if (your_map.size() != 3) {
      cout << "Erase test #1 failed: incorrect response to erasing a key not "
              "within your map.\n";
      return false;
    }

    // erase properly removes valid keys
    your_map.erase("x");
    if (your_map.size() != 2) {
      cout << "Erase test #2 failed: incorrect response to erasing a key "
              "within your map.\n";
      return false;
    }

    return true;
  });
}
