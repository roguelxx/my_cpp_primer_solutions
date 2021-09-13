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
  // move member
  Message(Message &&) noexcept;
  Message &operator=(Message &&);

  void save(Folder &);
  void remove(Folder &);

  void swap(Message &, Message &);

  const string & get() const;

  void move_Folders(Message *); // move folders from Message *m to this Message
 private:
  string contents;
  set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders(); // remove this Message from Folders
};

#endif //CPP_PRIME_CH13_13_34_MESSAGE_H_
