//
// Created by lxx on 2021/8/17.
//

#include <iostream>

using namespace std;

class numbered {
 public:
  numbered() : mysn(++sn) {
  }
  numbered(const numbered &) : mysn(++sn) {
  }
  int mysn;
 private:
  static int sn;
};

int numbered::sn = 0;

void f(numbered s) {
  cout << s.mysn << endl;
}

int main() {
  numbered a, b = a, c = b; // a.sn = 1, b.sn = 2, c.sn = 3
  f(a); // copy initialization, sn++ -> 4
  f(b); // 5
  f(c); // 6
  numbered d; // d.sn = 7
  f(d); // 8
}
