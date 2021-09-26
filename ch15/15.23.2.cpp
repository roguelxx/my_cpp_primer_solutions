//
// Created by xxlin on 2021/9/24.
//

class Base {
 public:
  virtual int fcn();
};

class D1 : public Base {
 public:
  int fcn() override;
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
  bp2->fcn(); // virtual call, call D1::fcn() at run time <--- changed
  bp3->fcn(); // virtual call, call D2::fcn() at run time
}
