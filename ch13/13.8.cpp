//
// Created by lxx on 2021/8/17.
//

#include <string>
#include <iostream>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr &operator=(const HasPtr &right) {
    std::cout << "copy assignment!" << std::endl;
    // This copy-assignment operator is wrong, see ex13.23 for correct version.
    i = right.i;
    ps = new std::string(*right.ps);
    return *this;
  }

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }
 private:
  std::string *ps;
  int i;
};
HasPtr::HasPtr(const HasPtr &ori) : i(ori.i), ps(new std::string(*ori.ps)) {
  std::cout << "copy constructor! from: " << ori.ps << std::endl;
//  i = ori.i;
//  ps = new std::string(*ori.ps);
}

int main() {
  HasPtr hp1("World");
  HasPtr hp2 = hp1; // copy initialization
  HasPtr hp3;
  hp3 = hp1; // copy-assignment
  hp1.set("Hello");

  std::cout << hp1.get() << std::endl;
  std::cout << hp2.get() << std::endl;
  std::cout << hp3.get() << std::endl;

  hp1 = hp1;
  std::cout << "After `hp1 = hp1`: " << hp1.get() << std::endl;

  return 0;
}

