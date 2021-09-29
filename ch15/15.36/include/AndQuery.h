//
// Created by xxlin on 2021/9/28.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ANDQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ANDQUERY_H_

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &, const Query &);
 private:
  AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") {
    std::cout << "AndQuery(const Query &l, const Query &r)" << std::endl;
  }
  // concrete class: AndQuery inherits rep() and defines the remaining pure virtual
  QueryResult eval(const TextQuery &) const override {
    return {};
  };
};

//inline Query operator&(const Query &lhs, const Query &rhs) {
//  return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
//}

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ANDQUERY_H_
