//
// Created by xxlin on 2021/9/26.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_TEXTQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_TEXTQUERY_H_

#include <memory>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>

using namespace std;

class QueryResult;

class TextQuery {
 public:
  explicit TextQuery(ifstream &);
  QueryResult query(const string &) const;
 private:
  shared_ptr<vector<string>> contents;
  map<string, shared_ptr<set<int>>> word_ln_map;
};

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_TEXTQUERY_H_
