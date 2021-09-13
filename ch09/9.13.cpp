//
// Created by lxx on 2021/8/11.
//

#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
  list<int> li{1, 2, 3, 4, 5};
  vector<double> vd(li.begin(), li.end());
  for (auto it: vd) {
    cout << it << " ";
  }
  cout << endl;
  vector<int> vi{1, 2, 3, 4, 5};
  vector<double> vd2(vi.begin(), vi.end());
  for (auto it: vd2) {
    cout << it << " ";
  }
  cout <<endl;
  return 0;
}
