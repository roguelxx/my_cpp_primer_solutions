//
// Created by lxx on 2021/8/24.
//

#include "Folder.h"
#include "Message.h"
#include <set>
#include <iostream>

void Folder::addMsg(Message *m) {
  messages.insert(m);
}

void Folder::remMsg(Message *m) {
  messages.erase(m);
}

void Folder::swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  for (auto &m : lhs.messages) {
    m->remove(lhs);
  }
  for (auto &m : rhs.messages) {
    m->remove(rhs);
  }
  swap(lhs.messages, rhs.messages);
  for (auto &m : lhs.messages) {
    m->save(lhs);
  }
  for (auto &m : rhs.messages) {
    m->save(rhs);
  }
}

int main() {
  std::set<int> s1{1, 2, 3};
  std::set<int> s2{4, 5, 6};
  std::swap(s1, s2);
  for (const auto si : s1) {
    std::cout << si << " ";
  }
  std::cout << std::endl;
  for (const auto si : s2) {
    std::cout << si << " ";
  }
}


