//
// Created by lxx on 2021/8/13.
//

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
  return p1.second < p2.second;
}

int main() {
  vector<pair<string, int>> vp;
  string s;
  int i;
  while (true) {
    cin >> s;
    if (s == "q") {
      break;
    }
    cin >> i;
//    vp.emplace_back(s, i);
    vp.emplace_back(make_pair(s, i));
  }
  for (const auto &it : vp) {
    cout << it.first << " --- " << it.second << endl;
  }
  cout << "after sorting" << endl;
  sort(vp.begin(), vp.end(), comp);
  for (const auto &it : vp) {
    cout << it.first << " --- " << it.second << endl;
  }
  return 0;
}
