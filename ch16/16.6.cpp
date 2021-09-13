//
// Created by lxx on 2021/9/12.
//

#include <iostream>

template<typename T, unsigned N>
T *begin(T (&arr)[N]) {
  return arr;
}

template<typename T, unsigned N>
const T *const_end(const T (&arr)[N]) {
  return arr + N;
}

int main() {
  int ia[5]{1, 2, 3, 4, 5};
  for (auto it = begin(ia); it != const_end(ia); ++it) {
    std::cout << *it << " ";
  }
}

