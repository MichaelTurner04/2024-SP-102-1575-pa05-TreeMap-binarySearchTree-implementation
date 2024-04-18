#include "MyMap.h"
#include "test_utils.hpp"
#include <ctime>
#include <map>
#include <stdlib.h>
#include <vector>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
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

    auto test_iter = test_map.begin();
    auto your_iter = test_vect.begin();

    // elements inserted in correct position
    for (int k = 0; k < 4; k++) {
      if (*your_iter++ != (*test_iter).second) {
        cout << "Insert test #1 failed: your insert function is incorrect.\n";
        return false;
      }
      test_iter++;
    }

    // insert does nothing with duplicate keys
    your_map.insert("j", 42);
    if (your_map.at("j") == 42 || your_map.size() == 5) {
      cout << "Insert test #2 failed: incorrect response to inserting a "
              "duplicate key. The insert function should do nothing in this "
              "case.\n";
      return false;
    }

    return true;
  });
}
