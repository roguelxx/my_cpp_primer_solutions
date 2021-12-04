//
// Created by xxlin on 2021/9/26.
//

#include "QueryResult.h"

ostream &print_result(ostream &os, const QueryResult &qr) {
  os << qr.word << " occurs " << qr.res_ln->size() << " times" << endl;
  for (const auto &ln: *qr.res_ln) {
    os << "\t(line " << ln + 1 << ") "
       << *(qr.res_contents->begin() + ln) << endl;
  }
  return os;
}
