//
// Created by xxlin on 2021/9/26.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_QUERYRESULT_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_QUERYRESULT_H_

#include <memory>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class QueryResult {
  friend ostream &print_result(ostream &, const QueryResult &);
 public:
  QueryResult() =default;
  QueryResult(string s, shared_ptr<vector<string>> contents, shared_ptr<set<int>> res_ln)
      : word(std::move(s)), res_contents(std::move(contents)), res_ln(std::move(res_ln)) {}
 private:
  string word;
  shared_ptr<vector<string>> res_contents;
  shared_ptr<set<int>> res_ln;
};

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH12_12_31_QUERYRESULT_H_
