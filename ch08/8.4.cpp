//
// Created by lxx on 2021/9/19.
//
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("/home/lxx/CLionProjects/my_cpp_primer_solutions/ch08/test.txt");
  if (fin) {
    vector<string> lines;
    string line;
    while (getline(fin, line)) {
      lines.emplace_back(line);
    }
    for (const auto &l : lines) {
      cout << l << endl;
    }
    fin.close();
  }
}
