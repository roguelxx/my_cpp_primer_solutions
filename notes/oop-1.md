# Overview

OOP的三个核心思想：数据抽象、继承、动态绑定。通过数据抽象，将class的接口与实现隔离开；通过继承，定义类型相似行为不同的class；通过动态绑定，在使用相似类型的对象时忽略不同类型之间的差异。

子类通过类继承表来指定所继承的父类，父类通过关键字virtual来定义希望子类自己实现的接口函数，子类通过关键字override指定要自己实现的父类的接口函数。如果子类没有重写父类的虚函数，则子类继承父类虚函数的默认实现。

```c++
class Quote {
public:
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
};

class Bulk_quote : public Quote { // Bulk_quote inherits from Quote
public:
	double net_price(std::size_t) const override;
};
```

当通过指向父类的指针、引用来调用虚函数时，会产生动态绑定。

```c++
// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n) {
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
```

子类虽然继承了父类的public、private成员，但是无法访问父类的private成员，只能访问父类的protected成员。类继承表中也有相应的access specifier，决定了子类的使用者（object）对子类继承表中相应的父类的可见度。

子类构造器会优先调用父类构造器，然后初始化子类自己的成员。如果我们没有明确调用哪一个父类构造器，默认调用父类的默认构造器。

我们可以通过关键字final来禁止一个类被继承，或一个父类函数被重写：

```c++
class NoDerived final { /* */ }; // NoDerived can't be a base class
class Base { /* */ };
// Last is final; we cannot inherit from Last
class Last final : Base { /* */ }; // Last can't be a base class
class Bad : NoDerived { /* */ }; // error: NoDerived is final
class Bad2 : Last { /* */ }; // error: Last is final
```

## Conversion and Inheritance

当一个类型涉及到继承时，对象的类型可以分为静态类型（static type）和动态类型（dynamic type）。静态类型在编译期间就可以知道，而动态类型只有在程序运行时才知道。以上述`print_total`为例：

```c++
double ret = item.net_price(n);
```

item的静态类型为`Quote&`，item的动态类型可能是`Quote&`也可能为它的子类。当然，如果变量既不是引用也不是指针，那么静态类型和动态类型一定是一致的。

当我们用子类对象来初始化父类时，父类构造器只会初始化父类自己的成员。

> When we initialize or assign an object of a base type from an object of a derived type, only the base-class part of the derived object is copied, moved, or assigned. The derived part of the object is ignored.

## Virtual Function

虚函数必须被实现，因为compiler不知道要调用子类还是父类的对应的函数。

引用或指针的静态类型和动态类型可能不同，使得OOP具备了多态的特征，只有在程序运行时才知道调用的是哪个类型的哪个虚函数。反过来，非引用指针对象的类型在编译期间就决定了。

父类中的虚函数在子类中也默认为虚函数（virtual），当子类要重写一个虚函数时，函数的参数必须与父类一致，函数的返回类型可能不一致。比如，D是B的子类，B中的虚函数返回B\*，D中的虚函数可以返回D\*。

> Virtual functions that have default arguments should use the same argument values in the base and derived classes.

可以通过范围限定符（::）来规定想要调用的虚函数：

```c++
// calls the version from the base class regardless of the dynamic type of baseP
double undiscounted = baseP->Quote::net_price(42);
```

这时不会触发动态绑定，在编译期间就知道了要调用的是哪个函数。