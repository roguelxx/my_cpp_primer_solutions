//
// Created by lxx on 2021/8/18.
//

#include <string>
#include <iostream>

using namespace std;

class Employee {
 public:
  Employee() = default;
  explicit Employee(const string &s) : name(s), myid(++auto_id) {}
  Employee(const Employee &ori) = default;
  int get_id() const {
    return myid;
  }
 private:
  string name;
  int myid;
  static int auto_id;
};

int Employee::auto_id = 0;

int main() {
  Employee e1("lxx"), e2("dy"), e3("cj");
  cout << e1.get_id() << endl;
  cout << e2.get_id() << endl;
  cout << e3.get_id() << endl;
}
