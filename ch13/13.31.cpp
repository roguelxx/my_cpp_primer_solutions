//
// Created by lxx on 2021/8/22.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

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

  bool operator<(const HasPtr &);

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

bool HasPtr::operator<(const HasPtr &rhs) {
  return *ps < *rhs.ps;
}

int main() {
  vector<HasPtr> vhs;
  vhs.emplace_back("c");
  vhs.emplace_back("b");
  vhs.emplace_back("a");
  std::cout << "before sort" << std::endl;
  for (const auto &hs : vhs) {
    std::cout << hs.get() << " ";
  }
  std::cout << std::endl;
  sort(vhs.begin(), vhs.end());
  for (const auto &hs : vhs) {
    std::cout << hs.get() << " ";
  }
}
