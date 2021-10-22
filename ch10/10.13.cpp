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

bool shorterThanFive(const std::string &s) {
  return s.size() < 5;
}

int main() {
  std::vector<std::string> vecc{"a23456", "b23", "z", "fox456", "mail567", "b", "fox", "cat456", "diss", "diss"};
  for (auto &v : vecc)
    std::cout << v << " ";
  std::cout << std::endl;
  std::partition(vecc.begin(), vecc.end(), shorterThanFive);
  for (auto &v : vecc)
    std::cout << v << " ";
  return 0;
}
