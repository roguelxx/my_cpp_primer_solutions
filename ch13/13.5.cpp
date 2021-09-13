//
// Created by lxx on 2021/8/17.
//

#include <string>
#include <iostream>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr &operator=(const HasPtr &rhs) {
//    delete ps;
//    i = rhs.i;
//    ps = new std::string(*rhs.ps);
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }
  ~HasPtr() {
    delete ps;
  };
  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }
 private:
  std::string *ps;
  int i;
};
HasPtr::HasPtr(const HasPtr &ori) : i(ori.i), ps(new std::string(*ori.ps)) {
//  i = ori.i;
//  ps = new std::string(*ori.ps);
}

int main() {
  HasPtr h1("Hello");
  HasPtr h2 = h1;
  h1.set("World");
  HasPtr h3("Yoyoyo");
  std::cout << h1.get() << " --- " << h2.get() << std::endl;
  h1 = h3;
  h1.set("Bangbangbang");
  std::cout << h1.get() << " --- " << h3.get() << std::endl;
  std::cout << "assign to itself" << std::endl;
  h1 = h1;
  std::cout << h1.get() << std::endl;
}

