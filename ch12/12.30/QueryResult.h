//
// Created by lxx on 2021/8/9.
//

#ifndef CPP_PRIME_QUERYRESULT_H
#define CPP_PRIME_QUERYRESULT_H


#include <string>
#include <vector>
#include <set>
#include <memory>
#include <ostream>

using namespace std;

class QueryResult {
  friend ostream &print(ostream &, const QueryResult &);
 public:
  QueryResult(string s, shared_ptr<set<int>> p, shared_ptr<vector<string>> f)
      : sought(s), lines(p), file(f) {
  }
 private:
  string sought;
  shared_ptr<vector<string>> file;
  shared_ptr<set<int>> lines;
};

#endif//CPP_PRIME_QUERYRESULT_H
