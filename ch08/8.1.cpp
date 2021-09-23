//
// Created by xxlin on 2021/9/15.
//

#include <iostream>
#include <string>
#include <sstream>

std::istream &my_print(std::istream &is) {
  std::string s;
  while (!is.eof()) {
    is >> s;
    std::cout << s;
  }
  return is;
}

std::istream &my_cin_print(std::istream &is) {
  is.clear();
  std::string s;
  while (is >> s) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  is.clear();
  return is;
}

void test_my_print(){
  std::string s;
  std::cin >> s;
  std::istringstream iss(s);
  my_print(iss);
}

void test_my_cin_print() {
  my_cin_print(std::cin);
}

int main() {
//  test_my_print();
  test_my_cin_print();
  return 0;
}

