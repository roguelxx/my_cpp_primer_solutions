//
// Created by lxx on 2021/8/9.
//

#ifndef CPP_PRIME_TEXTQUERY_H
#define CPP_PRIME_TEXTQUERY_H


#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <memory>
#include <sstream>

using namespace std;

class QueryResult;

class TextQuery {
 public:
  explicit TextQuery(ifstream &);
  QueryResult query(const string &) const;
 private:
  shared_ptr<vector<string>> file;
  map<string, shared_ptr<set<int>>> ln_map;
};


#endif//CPP_PRIME_TEXTQUERY_H
