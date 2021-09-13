//
// Created by lxx on 2021/8/10.
//
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

bool exist(vector<int>::iterator begin, const vector<int>::iterator end, int target) {
  while (begin != end) {
    if (*begin == target) {
      return true;
    }
    ++begin;
  }
  return false;
}

int main() {
  vector<int> v{1, 2, 3, 4, 5};
  if (exist(v.begin(), v.end(), 9)) {
    cout << "exist" << endl;
  } else {
    cout << "does not exist" << endl;
  }
  return 0;
}

