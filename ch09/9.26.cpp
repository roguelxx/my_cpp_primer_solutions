//
// Created by lxx on 2021/8/11.
//
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
//  vector<int> vi;
//  for (const auto &i:ia) {
//    vi.emplace_back(i);
//  }
  vector<int> vi(begin(ia), end(ia));
  list<int> li(vi.begin(), vi.end());
  for (auto it = vi.begin(); it != vi.end();) {
    if (!((*it) % 2)) {
      it = vi.erase(it);
    } else {
      ++it;
    }
  }
  for (auto it = li.begin(); it != li.end();) {
    if ((*it) % 2) {
      it = li.erase(it);
    } else {
      ++it;
    }
  }
  cout << "odd" << endl;
  for (const auto &i:vi) {
    cout << i << " ";
  }
  cout << endl << "even" << endl;
  for (const auto &i:li) {
    cout << i << " ";
  }
  return 0;
}

