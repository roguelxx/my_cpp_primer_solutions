//
// Created by lxx on 2021/8/11.
//
#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void find_and_insert_after(forward_list<string> &flst, const string &a, const string &b) {
  auto prev = flst.before_begin();
  auto curr = flst.begin();
  while (curr != flst.end()) {
    if (*curr == a) {
      flst.insert_after(curr, b);
      return;
    } else {
      prev = curr;
      ++curr;
    }
  }
  flst.insert_after(prev, b);
};

void print_flst(const forward_list<string> &flst) {
  for (const auto &it: flst) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  string a, b;
  forward_list<string> flst{"abc"};
  while (true) {
    cin >> a;
    if (a == "q") {
      break;
    }
    cin >> b;
    find_and_insert_after(flst, a, b);
    print_flst(flst);
  }
  return 0;
}
