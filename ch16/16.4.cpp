//
// Created by lxx on 2021/9/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using std::vector;
using std::cout;
using std::endl;

template<typename T, typename U>
int my_find_1(const T &container, const U &elem) {
  int idx = 0;
  for (auto iter = container.begin(); iter != container.end(); ++iter, ++idx) {
    if (*iter == elem) {
      return idx;
    }
  }
  return -1;
}

template<typename Iter, typename Val>
Iter my_find_2(Iter bg, Iter ed, const Val &elem) {
  for (; bg != ed; ++bg) {
    if (*bg == elem) {
      return bg;
    }
  }
  return bg;
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5 };
  auto it1 = my_find_2(vi.begin(), vi.end(), 3);
  if (it1 != vi.end())
    std::cout << *it1 << std::endl;
  else
    std::cout << "not found" << std::endl;
  auto it2 = my_find_2(vi.begin(), vi.end(), 8);
  if (it2 != vi.end())
    std::cout << *it2 << std::endl;
  else
    std::cout << "not found" << std::endl;

  std::list<std::string> ls { "abc", "def", "gh" };
  auto it3 = my_find_2(ls.begin(), ls.end(), "gh");
  if (it3 != ls.end())
    std::cout << *it3 << std::endl;
  else
    std::cout << "not found" << std::endl;
  auto it4 = my_find_2(ls.begin(), ls.end(), "hello");
  if (it4 != ls.end())
    std::cout << *it4 << std::endl;
  else
    std::cout << "not found" << std::endl;

  return 0;
}
