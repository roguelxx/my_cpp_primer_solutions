//
// Created by xxlin on 2021/9/9.
//

#include <iostream>
#include <string>

class Base {
 public:
  Base() = default;
  Base(const std::string &s) : basename(s) {}

  std::string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }
 private:
  std::string basename;
};

class Derived : public Base {
 public:
  Derived(const std::string &s, int ii) : Base(s), i(ii) {}
  void print(std::ostream &os) override {
    Base::print(os);
    os << " " << i;
  }
 private:
  int i;
};

int main() {
  Base b("abc");
  Derived d("cde", 2);
  b.print(std::cout);
  d.print(std::cout);
}
