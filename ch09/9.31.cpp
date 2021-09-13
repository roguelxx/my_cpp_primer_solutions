//
// Created by lxx on 2021/8/12.
//

#include <list>
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
  list<int> li{1, 2, 3, 4};
  auto it = li.begin();
  while (it != li.end()) {
    if (*it % 2) {
      it = li.insert(it, *it);
      ++it;
      ++it;
    } else {
      it = li.erase(it);
    }
  }
  for (const auto &l : li) {
    cout << l << " ";
  }
  cout << endl;
  forward_list<int> fli{1, 2, 3, 4};
  auto prev = fli.before_begin();
  auto curr = fli.begin();
  while (curr != fli.end()) {
    if (*curr % 2) {
      curr = fli.insert_after(prev, *curr);
      ++curr;
      prev = curr;
      ++curr;
    } else {
      curr = fli.erase_after(prev);
    }
  }
  for (const auto &fl: fli) {
    cout << fl << " ";
  }
  return 0;
}