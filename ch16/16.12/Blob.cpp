//
// Created by lxx on 2021/9/12.
//

#include "Blob.h"

//template<typename T>
//Blob<T>::Blob():data(make_shared<vector<T>>()) {}

template<typename T>
Blob<T>::Blob(initializer_list<T> il):data(make_shared<vector<T>(il)>()) {}

//template<typename T>
//void Blob<T>::check(std::size_t i, const string &msg) const {
//  if (i > size()) {
//    throw std::out_of_range(msg);
//  }
//}

//template<typename T>
//T& Blob<T>::back() {
//  check(0, "back() on empty Blob");
//  return data->back();
//}

template<typename T>
T& Blob<T>::operator[](size_type i) {
  check(i, "subscript out of range");
  return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back() on empty Blob");
  data->pop_back();
}
