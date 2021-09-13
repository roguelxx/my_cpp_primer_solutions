//
// Created by lxx on 2021/8/10.
//

#include "TextQuery.h"
#include "QueryResult.h"

QueryResult TextQuery::query(const string &word) const {
  static shared_ptr<set<int>> nodata(new set<int>);
  auto it = ln_map.find(word);
  if (it == ln_map.end()) {
    return QueryResult(word, nodata, file);
  } else{
    return QueryResult(word, it->second, file);
  }
}

TextQuery::TextQuery(ifstream &in_file):file(new vector<string>) {
  int ln_num = 0;
  string line;
  while (getline(in_file, line)) {
    file->emplace_back(line);
    istringstream iss(line);
    // diff
    string word;
    while (iss >> word) {
      auto &lines = ln_map[word];
      // careful, shared_ptr would be null
      if (!lines) {
        lines.reset(new set<int>);
      }
      lines->insert(ln_num);
    }
    ++ln_num;
  }
}
