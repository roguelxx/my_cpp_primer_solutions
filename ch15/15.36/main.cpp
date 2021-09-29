//
// Created by xxlin on 2021/9/28.
//

#include "Query.h"

int main() {
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout << q;
  return 0;
}
