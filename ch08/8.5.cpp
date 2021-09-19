//
// Created by lxx on 2021/9/19.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void func1() {
  ifstream fin("/home/lxx/CLionProjects/my_cpp_primer_solutions/ch08/test.txt");
  if (fin) {
    vector<string> words;
    for (string line; getline(fin, line);) {
      istringstream iss(line);
      for (string word; getline(iss, word, ' ');) {
        words.emplace_back(word);
      }
    }
    for (const auto &l : words) {
      cout << l << endl;
    }
    fin.close();
  }
}

void func2() {
  ifstream fin("/home/lxx/CLionProjects/my_cpp_primer_solutions/ch08/test.txt");
  if (fin) {
    vector<string> words;
    for (string word; fin >> word;) {
      words.emplace_back(word);
    }
    for (const auto &l : words) {
      cout << l << endl;
    }
    fin.close();
  }
}

int main() {
//  func2();
  ofstream fout("/home/lxx/CLionProjects/my_cpp_primer_solutions/ch08/test.txt", ios::app);
  if(fout) {
    fout.close();
  }
}
