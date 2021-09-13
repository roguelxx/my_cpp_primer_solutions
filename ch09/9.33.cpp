//
// Created by lxx on 2021/8/12.
//

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> vi{1, 2, 3, 4};
  auto it = vi.begin();
  while (it != vi.end()) {
    ++it;
//    it = vi.insert(it, 42);
    vi.insert(it, 42); // after insertion, it become invalid iterator, so we need to refresh it
//    ++it;
  }
  for (const auto &v: vi) {
    cout << v << " ";
  }
  return 0;
}
