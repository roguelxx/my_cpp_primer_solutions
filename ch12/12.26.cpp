//
// Created by lxx on 2021/8/8.
//

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(){
  int n = 10;
/*
  string *const p = new string[n];
  string s;
  string *q = p;
  while (cin >> s && q != p + n)
    *q++ = s;
  const size_t size = q - p;
  // use the array
  delete[] p;
*/


  allocator<string> alloc;
  auto p = alloc.allocate(n);
  auto q = p;
  string s;
  while (cin >> s && q != p + n) {
    alloc.construct(q++, s);
  }
  for (auto pos = p; pos != q; ++pos) {
    cout << *pos << " ";
  }
  while (q != p) {
    alloc.destroy(--q);
  }
  alloc.deallocate(p, n);

  return 0;
}
