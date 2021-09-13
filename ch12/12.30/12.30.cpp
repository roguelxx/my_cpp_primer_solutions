//
// Created by lxx on 2021/8/10.
//

#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void run_queries(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "enter word to look for, or q to quit: " << endl;
    string s;
    cin >> s;
    if (s == "q") {
      break;
    }
    print(cout, tq.query(s)) << endl;
  }
}

int main() {
  cout << "give me a filename to look for" << endl;
  string filename;
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cerr << "cannot open file \"" << filename << "\"." << endl;
    return -1;
  }
  run_queries(ifs);
  return 0;
}

