//
// Created by lxx on 2021/10/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

void eliminateDups(std::vector<std::string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto unique_end = std::unique(vec.begin(), vec.end());
  vec.erase(unique_end, vec.cend());
}

bool is_shorter_or_equal(const std::string &s, std::size_t sz) {
  return s.size() <= sz;
}

std::string make_plural(std::size_t count, const std::string &word, const std::string &ending) {
  return count > 1 ? word + ending : word;
}

void biggies(std::vector<std::string> &vec, std::vector<std::string>::size_type sz) {
  eliminateDups(vec);
  std::for_each(vec.begin(), vec.end(), [](const std::string &s) { std::cout << s << ","; });
  std::cout << std::endl;
  std::stable_sort(vec.begin(), vec.end(),
                   [](const std::string &s1, const std::string &s2) {
                     return s1.size() < s2.size();
                   });
  std::for_each(vec.begin(), vec.end(), [](const std::string &s) { std::cout << s << ","; });
  std::cout << std::endl;
//  auto first_big = std::find_if(vec.begin(), vec.end(),
//                                [sz](const std::string &s) {
//                                  return s.size() >= sz;
//                                });
//  auto count = vec.cend() - first_big;
  auto count = std::count_if(vec.begin(), vec.end(),
                             std::bind(is_shorter_or_equal, _1, sz));
  std::cout << count << " " << make_plural(count, "word", "s")
            << " of length " << sz << " or shorter" << std::endl;
//  std::for_each(first_big, vec.end(), [](const std::string &s) { std::cout << s << ","; });
}

int main() {
  std::vector<std::string> vecc{"a", "b", "z", "fox", "mail", "b", "fox", "cat", "diss", "diss"};
//  std::for_each(vecc.begin(), vecc.end(), [](const std::string &s) { std::cout << s << ","; });
//  std::cout << std::endl;
  biggies(vecc, 3);
  return 0;
}

