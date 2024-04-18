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

    // Bracket op adds new elements
    int r = rand() % 50;
    your_map["a"] = r;
    try {
      if (your_map.at("a") != r) {
        cout << "Bracket operator test #1 failed: bracket operator failed to "
                "add a new element.\n";
        return false;
      }
    } catch (...) {
      cout << "Bracket operator test #1 failed: exception encountered when "
              "trying to add a new element.\n";
      return false;
    }

    // Bracket op doesn't create duplicates
    your_map["a"] = r + 1;
    if (your_map.size() != 1) {
      cout << "Bracket operator test #2 failed: incorrect map size after "
              "updating an existing node's value. This could be caused by "
              "creating duplicates.\n";
      return false;
    }
    int test_val = your_map["a"];
    if (test_val != r + 1) {
      cout << "Bracket operator test #3 failed: incorrect value returned when "
              "accessing a node.\n";
      return false;
    }

    // TODO: multiple (~5) bracket ins test

    return true;
  });
}
