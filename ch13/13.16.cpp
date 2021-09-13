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

void f2(const numbered &s) {
  cout << s.mysn << endl;
}

int main() {
  numbered a, b = a, c = b; // a.sn = 1, b.sn = 2, c.sn = 3
  f2(a); // no copy initialization, 1
  f2(b); // 2
  f2(c); // 3
  numbered d; // d.sn = 4
  f2(d); // 4
}
