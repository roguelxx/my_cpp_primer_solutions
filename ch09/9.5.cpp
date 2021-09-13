//
// Created by lxx on 2021/8/10.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

vector<int>::const_iterator exist(vector<int>::const_iterator begin, const vector<int>::const_iterator end, int target) {
  while (begin != end) {
    if (*begin == target) {
      return begin;
    }
    ++begin;
  }
  return end;
}

int main() {
  const vector<int> v{1, 2, 3, 4, 5};
  auto it = exist(v.cbegin(), v.cend(), 4);
  if (it != v.end()) {
    cout << "exist" << endl;
  } else {
    cout << "does not exist" << endl;
  }
  return 0;
}

