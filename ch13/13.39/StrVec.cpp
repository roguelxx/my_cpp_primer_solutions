//
// Created by lxx on 2021/9/1.
//

#include "StrVec.h"

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
  if (size() == 0) {
    return;
  }
  alloc.destroy(--first_free);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *begin, const std::string *end) {
  auto p = alloc.allocate(end - begin);
  auto q = std::uninitialized_copy(begin, end, p);
  auto ret_pair = std::make_pair(p, q);
  return ret_pair;
}

void StrVec::free() {
  if (elements) {
    for (auto q = first_free; q != elements;) {
      alloc.destroy(--q);
    }
    alloc.deallocate(elements, cap - elements); //  must check elements is not nullptr
  }
}

StrVec::StrVec(const StrVec &ori) {
  auto res_pair = alloc_n_copy(ori.begin(), ori.end());
  elements = res_pair.first;
  first_free = cap = res_pair.second;
}

StrVec::~StrVec() {
  free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto res_pair = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = res_pair.first;
  first_free = cap = res_pair.second;
  return *this;
}

void StrVec::reallocate() {
  auto newcapacity = size() ? size() * 2 : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i < size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::reserve(size_t c) {
  if (c <= capacity()) {
    return;
  }
  auto newdata = alloc.allocate(c);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i < size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + c;
}

void StrVec::resize(size_t s, const std::string &init_v) {
  if (s > size()) {
    for (size_t i = size(); i < s; ++i) {
      push_back(init_v);
    }
  }
  if (s < size()) {
    for (size_t i = s; i < size(); ++i) {
      pop_back();
    }
  }
}
