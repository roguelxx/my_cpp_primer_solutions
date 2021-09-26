//
// Created by xxlin on 2021/9/24.
//

class Base {
 public:
  virtual int fcn();
};

class D1 : public Base {
 public:
  int fcn(int);
  virtual void f2();
};

class D2 : public D1 {
 public:
  int fcn(int);
  int fcn();
  void f2();
};

int main() {
  Base bobj;
  D1 d1obj;
  D2 d2obj;
  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  bp1->fcn(); // virtual call, call Base::fcn() at run time
  bp2->fcn(); // virtual call, call Base::fcn() at run time
  bp3->fcn(); // virtual call, call D2::fcn() at run time
  D1 *d1p = &d1obj;
  D2 *d2p = &d2obj;
  // bp2->f2(); // error, static type Base has no member named f2
  d1p->f2(); // virtual call, call D1::f2() at run time
  d2p->f2(); // virtual call, call D2::f2() at run time
  /* non-virtual function calls */
  Base *p1 = &d2obj;
  D1 *p2 = &d2obj;
  D2 *p3 = &d2obj;
  // p1->fcn(42); // error, static type Base has no version of fcn() that takes an int
  p2->fcn(42); // call D1::fcn(int)
  p3->fcn(42); // call D2::fcn(int)
}