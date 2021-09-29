//
// Created by xxlin on 2021/9/28.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_BINARYQUERY_H_
#define MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_BINARYQUERY_H_

#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query &l, const Query &r, const string &s) : lhs(l), rhs(r), opSym(s) {
    std::cout << "BinaryQuery(const Query &l, const Query &r, const string &s)" << std::endl;
  }
  // abstract class: BinaryQuery doesn't define eval()
  string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
  Query lhs, rhs; //right- and left-hand operands
  string opSym; // name of the operator
};

#endif //MY_CPP_PRIMER_SOLUTIONS_MY_CPP_PRIMER_SOLUTIONS_CH15_15_35_BINARYQUERY_H_
