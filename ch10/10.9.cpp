//
// Created by xxlin on 2021/10/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void eliminateDups(std::vector<std::string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto unique_end = std::unique(vec.begin(), vec.end());
  vec.erase(unique_end, vec.cend());
}

int main() {
  std::vector<std::string> vecc{"a", "b", "z", "fox", "mail", "b", "fox", "cat", "diss", "diss"};
  for (auto &v : vecc)
    std::cout << v << " ";
  std::cout << std::endl;
  eliminateDups(vecc);
  for (auto &v : vecc)
    std::cout << v << " ";
  return 0;
}
