//
// Created by lxx on 2021/8/11.
//

#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
  list<const char *> li{"a", "b", "c"};
  vector<string> vs;
  vs.assign(li.begin(), li.end());
  for (const auto& it : vs) {
    cout << it << " ";
  }
  return 0;
}
