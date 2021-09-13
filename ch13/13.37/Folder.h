//
// Created by lxx on 2021/8/24.
//

#ifndef CPP_PRIME_CH13_13_34_FOLDER_H_
#define CPP_PRIME_CH13_13_34_FOLDER_H_

#include <set>

using namespace std;

class Message;

class Folder {
  friend class Message;
 public:
  Folder() = default;
  void addMsg(Message *);
  void remMsg(Message *);

  void swap(Folder &, Folder &);
 private:
  set<Message *> messages;
};

#endif //CPP_PRIME_CH13_13_34_FOLDER_H_
