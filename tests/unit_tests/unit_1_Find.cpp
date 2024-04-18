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

    TreeNode<std::string, int> *found = your_map.find("j");
    if (found == nullptr) {
      cout << "Find test #1 failed: failed to find an element within your "
              "map.\n";
      return false;
    }
    found = your_map.find("x");
    if (found == nullptr) {
      cout << "Find test #2 failed: failed to find an element within your "
              "map.\n";
      return false;
    }
    found = your_map.find("a");
    if (found != nullptr) {
      cout << "Find test #3 failed: didn't return nullptr when trying to find "
              "an element that is not within your map.\n";
      return false;
    }

    return true;
  });
}
