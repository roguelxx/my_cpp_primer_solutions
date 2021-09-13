//
// Created by lxx on 2021/9/12.
//

#ifndef CPP_PRIME_CH16_16_12_BLOB_H_
#define CPP_PRIME_CH16_16_12_BLOB_H_

#include <memory>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Blob {
 public:
  typedef T value_type;
  typedef typename vector<T>::size_type size_type;
  Blob() : data(make_shared<vector<T>>()) {};
  Blob(initializer_list<T> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const T &t) { data->push_back(t); }
  // move version
  void push_back(const T &&t) { data->push_back(std::move(t)); }
  void pop_back();
  // element access
  T &back();
  T &operator[](size_type);
 private:
  shared_ptr<vector<T>> data;
  void check(std::size_t, const string &) const;
};

template<typename T>
T& Blob<T>::back() {
  check(0, "back() on empty Blob");
  return data->back();
}

template<typename T>
void Blob<T>::check(std::size_t i, const string &msg) const {
  if (i > size()) {
    throw std::out_of_range(msg);
  }
}

#endif //CPP_PRIME_CH16_16_12_BLOB_H_
