//
// Created by xxlin on 2021/9/28.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ORQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ORQUERY_H_

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);
 private:
  OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
  QueryResult eval(const TextQuery &) const override {
    return {};
  };
};

//inline Query operator|(const Query &lhs, const Query &rhs) {
//  return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
//}

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_ORQUERY_H_
