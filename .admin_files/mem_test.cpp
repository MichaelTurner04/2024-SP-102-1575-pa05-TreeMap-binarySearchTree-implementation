#include "../MyVector.h"
#include <ctime>
#include <stdlib.h>

int main() {
  time_t seed;
  srand(time(&seed));

  MyVector<int> v;

  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  for (int k = 0; k < 10; k++) {
    int r = rand() % 50;
    int ri = rand() % v.size();
    v.insert(ri, r);
  }

  MyVector<int> v2 = v;

  v.clear();
  v.push_back(0);
  v2.pop_back();
  v.shrink_to_fit();

  for (int j = 0; j < 5; j++) {
    int ri = rand() % v2.size();
    v2.erase(ri);
  }

  MyVector<int> v3;
  v3 = v2;

  v.push_back(7);
  v2.push_back(7);
  v3.push_back(7);

  return 0;
}
