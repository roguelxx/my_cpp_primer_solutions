//
// Created by lxx on 2021/10/23.
//
#include <iostream>

void func() {
  int cnt = 10;
  auto is_zero = [&cnt]() {
    if (cnt) {
      cnt--;
      return false;
    } else {
      return true;
    }
  };
  while (!is_zero()) {
    std::cout << cnt << std::endl;
  }
  is_zero();
  std::cout << cnt << std::endl;
}

int main() {
  func();
  return 0;
}

