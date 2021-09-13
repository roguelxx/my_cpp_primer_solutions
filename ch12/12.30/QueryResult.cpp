//
// Created by lxx on 2021/8/10.
//

#include "QueryResult.h"


ostream &print(ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " times." << endl;
  for(auto num: *qr.lines){
    os << "\t(line " << num + 1 << ") "
       << *(qr.file->begin() + num) << endl;
  }
  return os;
}

