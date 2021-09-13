//
// Created by lxx on 2021/8/11.
//
#include <vector>
#include <iostream>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::list;

bool equal(const list<int>& v1, const vector<int>& v2) {
  auto it1 = v1.begin();
  auto it2 = v2.begin();
  while (it1 != v1.end() && it2 != v2.end()) {
    if (*it1 > *it2) {
      return false;
    }
    ++it1;
    ++it2;
  }
  if (it1 != v1.end() || it2 != v2.end()) {
    return false;
  }
  return true;
}

int main() {
  list<int> l1{1, 2};
  vector<int> v1{1, 2, 3};
  if (equal(l1, v1)) {
    cout << "equal" << endl;
  } else {
    cout << "not equal" << endl;
  }
  return 0;
}

