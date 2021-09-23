//
// Created by xxlin on 2021/9/13.
//

#ifndef MY_CPP_PRIMER_SOLUTIONS_CH16_16_16_VEC_H_
#define MY_CPP_PRIMER_SOLUTIONS_CH16_16_16_VEC_H_

#include <string>
#include <memory>

template<typename T>
class Vec {
 public:
  Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  Vec(std::initializer_list<T>);

  // copy member
  Vec(const Vec &);
  Vec &operator=(const Vec &);
  ~Vec();

  // move member
  Vec(Vec &&);
  Vec &operator=(Vec &&);

  // access member
  void push_back(const T &);
  void pop_back();
  void reserve(std::size_t);
  void resize(std::size_t, const T &);

  std::size_t size() const { return first_free - elements; }
  std::size_t capacity() const { return cap - elements; }
  T *begin() const { return elements; }
  T *end() const { return first_free; }
 private:
  // allocator
  std::allocator<T> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  std::pair<T *, T *> alloc_n_copy(const T *, const T *);
  std::pair<T *, T *> alloc_n_move(const T *, const T *);
  void free();
  void reallocate();

  // data member
  T *elements;
  T *first_free;
  T *cap;
};

template<typename T>
void Vec<T>::reallocate() {
  auto newcapacity = size() ? size() * 2 : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (std::size_t i = 0; i < size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = newdata + newcapacity;
}

template<typename T>
void Vec<T>::push_back(const T &t) {
  chk_n_alloc();
  alloc.construct(first_free++, t);
}

#endif //MY_CPP_PRIMER_SOLUTIONS_CH16_16_16_VEC_H_
