//
// Created by xxlin on 2021/9/28.
//

#include "AndQuery.h"

Query operator&(const Query &lhs, const Query &rhs) {
  std::cout << "Query operator&(const Query &lhs, const Query &rhs)" << std::endl;
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
