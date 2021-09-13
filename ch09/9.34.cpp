//
// Created by lxx on 2021/8/12.
//

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> vi{1, 2, 3};
  auto it = vi.begin();
  while (it != vi.end()) {
    if (*it % 2) {
      it = vi.insert(it, *it);
    }
    ++it;
  }
  for (const auto &v:vi) {
    cout << v << " ";
  }
  return 0;
}