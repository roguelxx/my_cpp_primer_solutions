//
// Created by lxx on 2021/8/11.
//

#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  list<int> li{1, 2, 3, 4, 5};
  deque<int> odd_de, even_de;
  for (const auto &i:li) {
    if (i % 2) { // odd
      odd_de.emplace_back(i);
    } else {
      even_de.emplace_back(i);
    }
  }
  for (const auto &it: odd_de) {
    cout << it << " ";
  }
  cout << endl;
  for (const auto &it: even_de) {
    cout << it << " ";
  }
}
