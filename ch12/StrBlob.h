//
// Created by lxx on 2021/7/30.
//

#ifndef CPP_PRIME_STRBLOB_H
#define CPP_PRIME_STRBLOB_H

#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {
        return data->size();
    };
    bool empty() const {
        return data->empty();
    }
    void push_back(const string&);
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type, const string &) const;
};

inline void StrBlob::push_back(const string &s) {
    data->push_back(s);
}

#endif //CPP_PRIME_STRBLOB_H
