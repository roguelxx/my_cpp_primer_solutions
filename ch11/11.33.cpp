//
// Created by lxx on 2021/8/16.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

const string &transform(const map<string, string> &mp, const string &from) {
  auto f = mp.find(from);
  if (f == mp.end()) {
    return from;
  }
  return f->second;
};

map<string, string> buildMap(ifstream &trans_file) {
  map<string, string> mp;
  string key;
  string value;
  while (trans_file >> key && getline(trans_file, value)) {
    if (value.size() > 1) {
      mp[key] = value.substr(1);
    } else {
      throw runtime_error("no rule for " + key);
    }
  }
  return mp;
};

void word_transform(ifstream &trans_file, ifstream &in_file) {
  auto mp = buildMap(trans_file);
  string line;
  while (getline(in_file, line)) {
    istringstream iss(line);
    string word;
    bool firstword = true;
    while (iss >> word) {
      if (firstword) {
        firstword = false;
      } else {
        cout << " ";
      }
      cout << transform(mp, word);
    }
    cout << endl;
  }
}

int main() {
  const string &trans_f = "/home/lxx/CLionProjects/cpp_prime/ch11/trans.txt";
  const string &in_f = "/home/lxx/CLionProjects/cpp_prime/ch11/input.txt";
  ifstream trans_file(trans_f);
  ifstream input_file(in_f);
  word_transform(trans_file, input_file);
  return 0;
}
