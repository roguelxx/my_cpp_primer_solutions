//
// Created by lxx on 2021/8/17.
//

#include <iostream>
#include <vector>
#include <list>

struct X {
  X() {
    ++i;
    j = i;
    std::cout << "X() " << j << std::endl;
  }
  X(const X &ori) {
    ++i;
    j = i;
    std::cout << "X(const X &) " << ", from: " << ori.j << ", to: " << j << std::endl;
  }
  X &operator=(const X &rhs) {
    std::cout << "operator= " << "from: " << rhs.j << ", to: " << j << std::endl;
    return *this;
  }
  ~X() { std::cout << "~X() " << j << std::endl; }
  static int i;
  int j;
};

int X::i = 0;

void f1(X x) {
}

void f2(X &x) {
}

X f3() {
  return X();
}

X &f4(X &x) {
  return x;
}

X f5() {
  X x;
  return x;
}

int main() {
  std::cout << "\n----- X x1;\n";
  X x1; // X() 1
  std::cout << "\n----- f1(x1);\n";
  f1(x1); // X(const X&) 2 , copy initialization, ~X() 2
  std::cout << "\n----- f2(x1);\n";
  f2(x1); // nothing
  std::cout << "\n----- X x3 = f3();\n";
  X x3 = f3(); // X() 3
  std::cout << "\n----- f3();\n";
  f3(); // X() 4, ~X() 4
  std::cout << "\n----- X x5 = f5();\n";
  X x5 = f5(); // X() 5
  std::cout << "\n----- f5();\n";
  f5(); // X() 6, ~X() 6
  std::cout << "\n----- X x4 = f4(x1);\n";
  X x4 = f4(x1); // X(const X&) 7
  std::cout << "\n----- f4(x1);\n";
  f4(x1); // nothing
  std::cout << "\n----- X *x2 = new X;\n";
  X *x2 = new X; // X() 8
  std::cout << "\n----- std::vector<X> vx;\n";
  std::vector<X> vx; // nothing
//  vx.reserve(3);
  std::cout << "\n----- vx.push_back(x1);\n";
  vx.push_back(x1); // X(const X&) 9
  std::cout << "\n----- vx.push_back(*x2);\n";
  vx.push_back(*x2);  // The vector is reallocate here. X(const X&) 10, X(const X&) 11
  std::cout << vx[0].j;
  std::cout << "\n----- std::list<X> vl;\n";
  std::list<X> vl; // nothing
  std::cout << "\n----- vl.push_back(x1);\n";
  vl.push_back(x1); // X(const X&) 12
  std::cout << "\n----- vl.push_back(*x2);\n";
  vl.push_back(*x2);  // The list does not need reallocate. X(const X&) 13
  std::cout << "\n----- delete x2;\n";
  delete x2; // ~X() 8
  std::cout << "\n----- \n";

  return 0;
}
