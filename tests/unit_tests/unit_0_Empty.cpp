#include "MyMap.h"
#include "test_utils.hpp"
#include <ctime>
#include <map>
#include <stdlib.h>
#include <string>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    std::map<std::string, int> test_map;
    MyMap<std::string, int> your_map;

    // new map is empty
    if (your_map.empty() == false) {
      cout << "Empty test #1 failed: Your newly created map isn't empty when "
              "it should be. This may just be a problem with your \'.empty\' "
              "function.\n";
      return false;
    }

    // maps with elements are non-empty
    your_map.begin() = new TreeNode<std::string, int>("a", 1);
    if (your_map.empty() == true) {
      cout << "Empty test #2 failed: Your map is empty after adding an element "
              "to it. This may just be a problem with your \'.empty\' "
              "function.\n";
      return false;
    }

    return true;
  });
}
