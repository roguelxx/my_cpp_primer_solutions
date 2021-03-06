//
// Created by lxx on 2021/8/22.
//


#include <string>
#include <iostream>

// Valuelike version
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
 public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) {}
  ~HasPtr();

  HasPtr &operator=(HasPtr rhs);

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

 private:
  std::string *ps;
  int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "Swap between <" << *lhs.ps << "> and <"
            << *rhs.ps << ">" << std::endl;
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

HasPtr::~HasPtr() {
  delete ps;
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
  // This copy-assignment operator is correct even if the object is assigned to
  // itself. See ex13.11 for the wrong version.
  swap(*this, rhs);
  return *this;
}

int main() {
  HasPtr hp1("World");
  HasPtr hp2 = hp1;
  HasPtr hp3;
  hp3 = hp1;
  hp1.set("Hello");

  std::cout << "hp1: " << hp1.get() << std::endl;
  std::cout << "hp2: " << hp2.get() << std::endl;
  std::cout << "hp3: " << hp3.get() << std::endl;

  hp1 = hp1;
  std::cout << "After `hp1 = hp1`: " << hp1.get() << std::endl;

  swap(hp1, hp2);
  std::cout << "hp1: " << hp1.get() << std::endl;
  std::cout << "hp2: " << hp2.get() << std::endl;

  swap(hp1, hp1);
  std::cout << "hp1: " <<  hp1.get() << std::endl;

  return 0;
}
