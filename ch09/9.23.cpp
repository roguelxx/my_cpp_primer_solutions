//
// Created by lxx on 2021/8/11.
//
#include <vector>
#include <iostream>


int main() {
  std::vector<int> vi;

  // All of them will cause program terminate in VS2015.
//  int i1 = vi.at(0);
  int i2 = vi[0];
  int i3 = vi.front();
  int i4 = *vi.begin();

//  std::cout << i1 << std::endl;
  std::cout << i2 << std::endl;
  std::cout << i3 << std::endl;
  std::cout << i4 << std::endl;
  return 0;
}
