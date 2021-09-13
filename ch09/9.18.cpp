//
// Created by lxx on 2021/8/11.
//

#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<string> dq;
  auto it = dq.begin();
  string s;
  while (cin >> s && s != "q") {
    it = dq.insert(it, s);
  }
  for (const auto &dqs: dq) {
    cout << dqs << " ";
  }
  return 0;
}