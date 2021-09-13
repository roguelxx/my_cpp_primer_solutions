//
// Created by lxx on 2021/7/30.
//

#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr():curr(0), wptr() {}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_type pos):curr(pos), wptr(a.data) {}

shared_ptr<vector<string>> StrBlobPtr::check(size_type i, const string &msg) const {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= sp->size()) {
        throw out_of_range(msg);
    }
    return sp;
}

string & StrBlobPtr::deref() const {
    auto sp = check(curr, "deref past end of StrBlobPtr");
    return (*sp)[curr];
}

StrBlobPtr & StrBlobPtr::incr() {
    check(curr, "incr past end of StrBlobPtr");
    ++curr;
    return *this;
}
