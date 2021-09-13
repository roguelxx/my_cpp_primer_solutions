//
// Created by lxx on 2021/8/16.
//

#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
  multimap<string, string> mss{{"lxx", "1"}, {"dy", "2"}, {"cj", "3"}, {"cpow", "4"}};
  auto f = mss.find("dy1");
  if (f == mss.end()) {
    cout << "do not exist." << endl;
  } else {
    mss.erase(f);
  }
  for (const auto &p : mss) {
    cout << p.first << " --- " << p.second << endl;
  }
  return 0;
}
