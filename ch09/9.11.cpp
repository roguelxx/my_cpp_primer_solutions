//
// Created by lxx on 2021/8/11.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print_v(const vector<int>& v){
  for (const auto i : v) {
    cout << i << " ";
  }
  cout<<endl;
}

int main() {
  vector<int> v1{1,2,3,4,5}; // list initialization
  vector<int> v2(v1); // copy initialization , 1,2,3,4,5
  vector<int> v3(v1.begin(), v1.begin() + 3); // 1,2,3
  vector<int> v4(5, 1); // size, element , 1,1,1,1,1
  vector<int> v0;
  vector<int> v5 = v0;
}
