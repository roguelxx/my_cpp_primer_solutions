//
// Created by lxx on 2021/9/12.
//

#include <iostream>
#include <string>
#include <vector>

template<typename T>
int compare(const T &v1, const T &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

int main() {
  int a = 1, b = 2;
  std::cout << compare(a, b) << std::endl;
  std::string sa = "c", sb = "bcde";
  std::cout << compare(sa, sb) << std::endl;
  std::vector<int> va{5, 6, 7};
  std::vector<int> vb{1, 2, 3};
  std::cout << compare(va, vb) << std::endl;
  std::cout << compare("abc", "cde") << std::endl;
}

