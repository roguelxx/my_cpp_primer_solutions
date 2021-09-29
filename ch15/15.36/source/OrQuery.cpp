//
// Created by xxlin on 2021/9/28.
//

#include "OrQuery.h"

Query operator|(const Query &lhs, const Query &rhs) {
  std::cout << "Query operator|(const Query &lhs, const Query &rhs)" << std::endl;
  return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
