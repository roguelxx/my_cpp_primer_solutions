//
// Created by lxx on 2021/9/12.
//

#include "Blob.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  Blob<int> bs;
  bs.push_back(1);
  cout << bs.back() << endl;
  return 0;
}
