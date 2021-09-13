//
// Created by lxx on 2021/8/11.
//
#include <vector>

using namespace std;

int main() {
  vector<int> iv{1, 2, 3, 4, 5};
  auto iter = iv.begin(), mid = iv.begin() + iv.size()/2;
  int some_val = 2;
  while (iter != mid) {
    if (*iter == some_val) {
      iv.insert(iter, 2 * some_val);  // Error, we should update the iter
//      iter = iv.insert(iter, 2 * some_val);
//      ++iter;  // Increament to point to the original value
    }
//    ++iter;  // Increment to point to the next value
  }
}
