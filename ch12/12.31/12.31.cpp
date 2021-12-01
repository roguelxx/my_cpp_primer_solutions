//
// Created by xxlin on 2021/9/26.
//

#include "TextQuery.h"
#include "QueryResult.h"

int main() {
  for (string filename; cout << "give a file name or enter q to exit" << endl, cin >> filename;) {
    if (filename == "q") {
      break;
    }
    ifstream fin(filename);
    if (!fin) {
      cerr << "can not open file: " << filename << endl;
      break;
    }
    TextQuery tq(fin);
    for (string word; cout << "give a word to search:" << endl, cin >> word;) {
      if (word == "q") {
        break;
      }
      print_result(cout, tq.query(word));
    }
  }
  return 0;
}