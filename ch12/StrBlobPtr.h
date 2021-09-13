//
// Created by lxx on 2021/7/30.
//

#ifndef CPP_PRIME_STRBLOBPTR_H
#define CPP_PRIME_STRBLOBPTR_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

class StrBlob;

class StrBlobPtr {
public:
    typedef vector<string>::size_type size_type;
    StrBlobPtr();

    explicit StrBlobPtr(StrBlob &a, size_type pos = 0);

    string & deref() const;
    StrBlobPtr &incr();
private:
    weak_ptr<vector<string>> wptr;
    size_type curr;
    shared_ptr<vector<string>> check(size_type, const string &) const;
};

#endif //CPP_PRIME_STRBLOBPTR_H
