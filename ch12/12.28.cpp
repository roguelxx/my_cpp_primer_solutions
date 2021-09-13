//
// Created by lxx on 2021/8/8.
//
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void run_queries(ifstream &file);

int main() {
  cout << "Please give me a filename:" << endl;
  string filename;
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cerr << "Cannot open file: " << filename << endl;
    return -1;
  }
  run_queries(ifs);
  return 0;
}

void init_text(ifstream &, vector<string> &, map<string, set<int>> &);

void run_queries(ifstream &file) {
  vector<string> text;
  map<string, set<int>> ln_map;
  init_text(file, text, ln_map);
  while (true) {
    cout << "Please give me a word:" << endl;
    string word;
    cin >> word;
    if (word == "q") {
      break;
    }
    auto it = ln_map.find(word);
    if (it == ln_map.end()) {
      cout << "There are no \"" << word << "\" in this file." << endl;
      continue;
    }
    int total = 0;
    for (const auto ln_num : it->second) {
      string line = text[ln_num];
      istringstream iss(line);
      for (string wd; iss >> wd;) {
        if (wd == word) {
          ++total;
        }
      }
    }
    cout << "\"" << word << "\" occurs " << total << " times." << endl;
    for (const auto ln_num : it->second) {
      cout << "(line " << ln_num + 1 << ") " << text[ln_num] << endl;
    }
  }
}

void init_text(ifstream &file, vector<string> &text, map<string, set<int>> &ln_map) {
  int ln_num = 0;
  string line;
  while (getline(file, line)) {
    text.emplace_back(line);
    istringstream iss(line);
    for (string word; iss >> word;) {
      ln_map[word].insert(ln_num);
    }
    ++ln_num;
  }
}
