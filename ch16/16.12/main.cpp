//
// Created by lxx on 2021/9/12.
//

#include <iostream>
#include <string>

#include "Blob.h"
#include "BlobPtr.h"

using std::cout;
using std::endl;
using std::string;

void BlobSimpleTest() {
  Blob<string> bs{"a", "b", "c"};
  cout << bs.size() << endl;
  bs.push_back("d");
  bs.push_back("e");
  cout << bs.size() << endl;
  for (; !bs.empty();) {
    cout << bs.back() << " ";
    bs.pop_back();
  }
  cout << endl;
  bs.push_back("lxx");
  bs.push_back("dy");
  bs.push_back("cj");
  bs.push_back("cpow");
  cout << bs.size() << endl;
  for (int i = 0; i < bs.size(); ++i) {
    cout << bs[i] << " ";
  }
  cout << endl;
}

void BlobPtrSimpleTest() {
  Blob<string> bs{"a", "b", "c"};
  BlobPtr<string> bspt(bs);
  cout << bspt.deref() << " ";
  bspt.incr();
  cout << bspt.deref() << " ";
  bspt.incr();
  cout << bspt.deref() << " ";
  bspt.incr();
  bs.push_back("d");
  cout << bspt.deref() << " ";
}

int main() {
//  BlobSimpleTest();
  BlobPtrSimpleTest();
  return 0;
}
