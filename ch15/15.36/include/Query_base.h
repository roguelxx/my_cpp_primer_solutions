//
// Created by xxlin on 2021/9/27.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_BASE_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_BASE_H_

//#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
//#include "Query.h"

// abstract class acts as a base class for concrete query types; all members are private
class Query_base {
  friend class Query;
//  friend class AndQuery;
//  friend class NotQuery;
//  friend class OrQuery;
//  friend class BinaryQuery;
 public:
  Query_base() {
    std::cout << "Query_base()" << std::endl;
  }
 protected:
  // using line_no = TextQuery::line_no; // used in the eval functions
  virtual ~Query_base() = default;
 private:
// public:
  // returns the QueryResult that matches this Query
  virtual QueryResult eval(const TextQuery &) const = 0;
  // a string representation of the query
  virtual string rep() const = 0;
};

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_QUERY_BASE_H_
