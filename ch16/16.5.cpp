//
// Created by lxx on 2021/9/12.
//

#include <iostream>
#include <string>

template<typename T, unsigned N>
void print(const T (&array)[N]) {
  for (int i = 0; i < N; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

struct C {
  int i;
  double d;
};

std::ostream &operator<<(std::ostream &os, const C &c) {
  return os << "{" << c.i << ", " << c.d << "}";
}

int main() {
  int ia[3]{2, 3, 4};
  std::string sa[3]{"a", "b", "c"};
  C ca[3]{{1, 2}, {2, 3}, {3, 4}};
  print(ia);
  print(sa);
  print(ca);
}
