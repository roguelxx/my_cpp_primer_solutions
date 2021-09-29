//
// Created by xxlin on 2021/9/27.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_H_

//#include "Query_base.h"
#include "WordQuery.h"

class TextQuery;
class QueryResult;
class Query_base;

#include <memory>
#include <string>
#include <iostream>

// interface class to manage the Query_base inheritance hierarchy
class Query {
  // these operators need access to the shared_ptr constructor
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);
 public:
//  Query(Query &&q) noexcept {
//    std::cout << "Query(Query &&q)" << std::endl;
//  }
//  Query(const Query &q) {
//    std::cout << "Query(const Query &q)" << std::endl;
//  }
  Query(const std::string &s) : q(new WordQuery(s)) {
    std::cout << "Query::Query(const std::string &)" << std::endl;
  }; // builds a new WordQuery
  // interface functions: call the corresponding Query_base operations
  QueryResult eval(const TextQuery &t) const { return q->eval(t); }
  std::string rep() const { return q->rep(); };
 private:
  Query(std::shared_ptr<Query_base> query) : q(query) {
    std::cout << "Query::Query(std::shared_ptr<Query_base>)" << std::endl;
  }
//  Query(const std::string &s) : q(new WordQuery(s)) {}
  std::shared_ptr<Query_base> q;
};

// why can not declare inside class ?
inline std::ostream &operator<<(std::ostream &os, const Query &query) { return os << query.rep(); }

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_H_
