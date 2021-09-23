//
// Created by xxlin on 2021/9/14.
//

//template<typename T, U,typename V> void f1(T, U, V);
template<typename T, typename U, typename V> void f1(T, U, V);

//template<typename T> T f2(int &T);
template<typename T> T f2(T &);

inline template<typename T> T foo(T, unsigned int *);
