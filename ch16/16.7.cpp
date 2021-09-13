//
// Created by lxx on 2021/9/12.
//

#include <iostream>

template<typename T, std::size_t N>
constexpr std::size_t size_arr(const T (&arr)[N]) {
  return N;
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  constexpr std::size_t sz = size_arr(arr);

  std::cout << sz << " " << size_arr(arr) << std::endl;

  return 0;
}
