//
// Created by lxx on 2021/9/12.
//

#ifndef CPP_PRIME_CH16_16_12_BLOBPTR_H_
#define CPP_PRIME_CH16_16_12_BLOBPTR_H_

#include <vector>
#include <memory>

using namespace std;

template<typename T>
class Blob;

template<typename T>
class BlobPtr {
 public:
  typedef typename vector<T>::size_type size_type;
  BlobPtr() : curr(0), wkpt(nullptr) {}
  BlobPtr(Blob<T> &, size_type pos = 0);

  T &deref() const;
  BlobPtr<T> &incr();
 private:
  size_type curr;
  weak_ptr<vector<T>> wkpt;
  shared_ptr<vector<T>> check(size_type, const string &) const;
};

template<typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, size_type pos):wkpt(a.data), curr(pos) {}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type i, const string &msg) const {
  auto sp = wkpt.lock();
  if (!sp) {
    throw runtime_error("unbound BlobPtr.");
  }
  if (i >= sp->size()) {
    throw std::out_of_range(msg);
  }
  return sp;
}

template<typename T>
T &BlobPtr<T>::deref() const {
  auto sp = check(curr, "deref() past end of BlobPtr");
  return (*sp)[curr];
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::incr() {
  auto ap = check(curr, "incr() past end of BlobPtr");
  ++curr;
  return *this;
}

#endif //CPP_PRIME_CH16_16_12_BLOBPTR_H_
