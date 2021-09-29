//
// Created by xxlin on 2021/9/28.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_NOTQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_NOTQUERY_H_

#include "Query_base.h"

class NotQuery : public Query_base {
 private:
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}
  string rep() const override { return "~(" + query.rep() + ")"; }
  QueryResult eval(const TextQuery &) const override {
    return {};
  };
  Query query;
};

inline Query operator~(const Query &operand) {
//  shared_ptr<Query_base> tmp(new NotQuery(operand));
//  return Query(tmp);
  return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_NOTQUERY_H_
