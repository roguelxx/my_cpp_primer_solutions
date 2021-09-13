//
// Created by lxx on 2021/8/24.
//

#include "Folder.h"
#include "Message.h"

void Folder::addMsg(Message *m) {
  messages.insert(m);
}

void Folder::remMsg(Message *m) {
  messages.erase(m);
}


