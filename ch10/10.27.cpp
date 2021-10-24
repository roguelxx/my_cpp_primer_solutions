//
// Created by lxx on 2021/10/24.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
  std::vector<int> vec{10, 9, 8, 8, 1, 2, 3, 2, 2, 4, 4, 5, 7, 6};
  std::sort(vec.begin(), vec.end());
  std::vector<int> unique_v;
  std::unique_copy(vec.begin(), vec.end(), std::back_inserter(unique_v));
  std::for_each(unique_v.begin(), unique_v.end(), [](int e){ std::cout << e << " "; });
}