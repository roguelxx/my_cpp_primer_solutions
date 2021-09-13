//
// Created by lxx on 2021/8/19.
//

#include <string>
#include <iostream>

using namespace std;

class HasPtr {
 public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
  HasPtr(const HasPtr &ori);
  HasPtr &operator=(const HasPtr &rhs);
  const string &get() const {
    return *ps;
  }
  void set(const string &s) const {
    *ps = s;
  }
  const size_t &get_use() const {
    return *use;
  }
  ~HasPtr() {
    if (--*use == 0) {
      cout << "destroy: " << *ps << endl;
      delete ps;
      delete use;
    }
  }
 private:
  string *ps;
  int i;
  size_t *use; // reference count
};

HasPtr::HasPtr(const HasPtr &ori) {
  ps = ori.ps;
  i = ori.i;
  use = ori.use;
  ++*use;
}

HasPtr & HasPtr::operator=(const HasPtr &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  use = rhs.use;
  ps = rhs.ps;
  i = rhs.i;
  return *this;
}

int main() {
  cout << "default constructor" << endl;
  HasPtr p1("p1");
  cout << p1.get() << ", " << p1.get_use() << endl;
  cout << "copy constructor" << endl;
  HasPtr p2 = p1;
  cout << p2.get() << ", " << p2.get_use() << endl;
  cout << "modify string" << endl;
  p2.set("p2");
  cout << p1.get() << ", " << p2.get() << endl;
  cout << "copy assignment" << endl;
  HasPtr p3("p3");
  p3 = p1;
  cout << p3.get() << ", " << p3.get_use() << endl;
  p3 = p3;
  cout << p3.get() << ", " << p3.get_use() << endl;
  return 0;
}
