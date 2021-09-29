//
// Created by xxlin on 2021/9/28.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_WORDQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_WORDQUERY_H_

#include "Query_base.h"
#include "TextQuery.h"
#include "QueryResult.h"

//class Query_base;

class WordQuery : public Query_base {
  friend class Query; // Query uses the WordQuery constructor
 private:
  WordQuery(const std::string &s) : query_word(s) {
    std::cout << "WordQuery(const std::string &s)" << std::endl;
  }
  QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
  string rep() const override { return query_word; }
  string query_word;
};

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_WORDQUERY_H_
