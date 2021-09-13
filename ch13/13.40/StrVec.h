//
// Created by lxx on 2021/9/1.
//

#ifndef CPP_PRIME_CH13_13_39_STRVEC_H_
#define CPP_PRIME_CH13_13_39_STRVEC_H_

#include <string>
#include <memory>

class StrVec {
 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string>);
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  ~StrVec();
  void push_back(const std::string &);
  void pop_back();
  void reserve(size_t);
  void resize(size_t, const std::string & = std::string());
  size_t size() const { return first_free - elements; };
  size_t capacity() const { return cap - elements; };
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
 private:
  std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif //CPP_PRIME_CH13_13_39_STRVEC_H_
