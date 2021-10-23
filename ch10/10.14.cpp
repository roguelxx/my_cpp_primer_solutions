//
// Created by lxx on 2021/10/23.
//
#include <iostream>

int main() {
  auto lambdd = [](int a, int b) -> int { return a + b; };
  std::cout << lambdd(3, 4);
  return 0;
}

