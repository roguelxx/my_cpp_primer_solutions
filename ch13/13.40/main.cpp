//
// Created by lxx on 2021/9/1.
//

#include <iostream>
#include "StrVec.h"

void print(const StrVec &sv) {
  std::cout << "<" << &sv << "> size: " << sv.size()
            << " capacity: " << sv.capacity() << " contents:";
  for (const auto &s : sv)
    std::cout << " <" << s << ">";
  std::cout << std::endl;
}

int main() {
  StrVec sv2 { "il1", "il2", "il3", "il4", "il5" }; print(sv2);
//  StrVec sv3 = { "il1", "il2", "il3", "il4", "il5" }; print(sv3);

  return 0;
}
