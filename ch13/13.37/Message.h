//
// Created by lxx on 2021/8/24.
//

#ifndef CPP_PRIME_CH13_13_34_MESSAGE_H_
#define CPP_PRIME_CH13_13_34_MESSAGE_H_

#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
  friend class Folder;
 public:
  explicit Message(const string &s = "") : contents(s) {}
  // copy member
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  void save(Folder &);
  void remove(Folder &);

  void swap(Message &, Message &);

  const string & get() const;
 private:
  string contents;
  set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

#endif //CPP_PRIME_CH13_13_34_MESSAGE_H_
