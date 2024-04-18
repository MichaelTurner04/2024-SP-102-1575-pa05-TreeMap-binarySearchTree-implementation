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

    MyMap<std::string, int> other_map = your_map;

    std::vector<int> test_vect;
    std::vector<int> other_vect;
    your_map.convert_to_sorted_list(your_map.begin(), test_vect);
    other_map.convert_to_sorted_list(other_map.begin(), other_vect);

    auto test_iter = test_vect.begin();
    auto other_iter = other_vect.begin();

    for (int k = 0; k < 3; k++) {
      if (*test_iter++ != *other_iter++) {
        cout << "Your copy constructor function is incorrect.\n";
        return false;
      }
    }

    // deep copy test
    your_map.begin()->value = 4;
    if (other_map.begin()->value == 4) {
      cout << "Your copy constructor function creates a shallow copy instead "
              "of a deep copy.\n";
      return false;
    }

    return true;
  });
}
