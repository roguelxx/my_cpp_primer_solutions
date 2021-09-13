//
// Created by lxx on 2021/8/24.
//

#include "Message.h"
#include "Folder.h"

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::remove_from_Folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}

Message::Message(const Message &ori) : contents(ori.contents), folders(ori.folders) {
  add_to_Folders(ori);
}

Message::~Message() {
  remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

void Message::save(Folder &f) {
  f.addMsg(this);
  folders.insert(&f);
}

void Message::remove(Folder &f) {
  f.remMsg(this);
  folders.erase(&f);
}

void Message::swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto &f : lhs.folders) {
    f->remMsg(this);
  }
  for (auto &f : rhs.folders) {
    f->addMsg(this);
  }
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto &f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto &f : rhs.folders) {
    f->addMsg(&rhs);
  }
}

const string & Message::get() const {
  return contents;
}
