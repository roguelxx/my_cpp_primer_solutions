//
// Created by xxlin on 2021/9/26.
//

#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(ifstream &fin) : contents(new vector<string>) {
  int ln_num = 0;
  for (string line; getline(fin, line);) {
    stringstream ss(line);
    contents->emplace_back(line);
    for (string word; ss >> word;) {
      if (word_ln_map.find(word) == word_ln_map.end()) {
        word_ln_map[word] = make_shared<set<int>>();
      }
      word_ln_map[word]->insert(ln_num);
    }
    ++ln_num;
  }
}

QueryResult TextQuery::query(const string &s) const {
  auto it = word_ln_map.find(s);
  if (it == word_ln_map.end()) {
    return {s, contents, make_shared<set<int>>()};
  } else {
    return {s, contents, it->second};
  }
}
