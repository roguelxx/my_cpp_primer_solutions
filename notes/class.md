## pointer to const

普通的指针不能指向const对象，同时我们不可以通过const指针来修改对象的值：

```c++
const double pi = 3.14; // pi is const; its value may not be changed
double *ptr = &pi; // error: ptr is a plain pointer
const double *cptr = &pi; // ok: cptr may point to a double that is const
*cptr = 42; // error: cannot assign to *cptr
```

但是指向const的指针也是可以指向non const对象的：

```c++
double dval = 3.14; // dval is a double; its value can be changed
cptr = &dval; // ok: but can't change dval through cptr
```

但是不能再通过这个指针对对象进行修改。所以，我们不能通过指向const的指针对对象进行修改，但是这个指针可以指向const对象和non const对象。

> It may be helpful to think of pointers and references to const as pointers or references “that think they point or refer to const.”

## const pointer

不同于引用，指针也算对象，所以我们可以用const关键字来修饰指针。const指针必须被初始化，一旦初始化完成后，我们就无法修改它的值（它指向的对象）。在`*`后加const关键字来申明const指针。

```c++
int errNumb = 0;
int *const curErr = &errNumb; // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

## top-level const

我们称对象本身是const的为top-level const，指向const对象的指针或引用称为low-level const。top-level const可以用在任意对象上，表示这个对象是const的，不可以修改；low-level const只能用在指针或引用上。指针对象比较特殊，即可以使top-level const也可以是low-level const。

在拷贝对象的时候，不会改变被拷贝对象的信息，被拷贝对象是否是const的是无关紧要的，所以top-level const被忽略：

```c++
int i = 0;
int *const p1 = &i; // we can't change the value of p1; const is top-level
const int ci = 42; // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci; // const in reference types is always low-level

i = ci; // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
```

但是low-level const不能被忽略，要么进行拷贝的两个对象有相同的low-level const，要么对象之间的const等级可以互相转化，即non const转化为const：

```c++
int *p = p3; // error: p3 has a low-level const but p doesn't
p2 = p3; // ok: p2 has the same low-level const qualification as p3
p2 = &i; // ok: we can convert int* to const int*
int &r = ci; // error: can't bind an ordinary int& to a const int object
const int &r2 = i; // ok: can bind const int& to plain int
```

const 指针或引用可以与non const对象绑定，也可以与const对象绑定，non const指针或引用只能与non const对象绑定。

## exercise

```c++
int i = -1, &r = 0; // error: non-const reference cannot be initialized to literal
const int i = -1, &r = 0; // ok
```

- non const指针、引用不能与const指针、引用绑定

## const member function

通过在参数列表后添加`const`关键字来定义const成员函数。定义const成员函数的目的在于隐式的修改`this`的类型，从而允许const object也可以调用const成员函数。

默认情况下，this是一个指向non-const class type的const指针。以`Sales_data`为例，`Sales_data`内的成员函数的this隐式的绑定为`Sales_data *const `，这就使得`const Sales_data`无法调用其成员函数，因为non const 指针不能与const对象绑定。

所以C++通过const member function来改变this为`const Sales_data *const`，这就使得const对象可以调用const成员函数，但是不能调用non const成员函数。

> Objects that are const, and references or pointers to const objects, may call only const member functions.

所以const成员函数必须保证，函数主体内不会修改调用者的信息。

- Any direct use of a member of the class is assumed to be an implicit reference through `this`

- compiler processes member declarations first, then the member function

- function that return `this` object

  - ```c++
    Object& func(){
        return *this;
    }
    ```

- The compiler generates a default constructor automatically only if a class declares no constructors.

- why we should write our own constructor

  - if a class requires control to initialize an object
  - objects of built-in or compound type (such as arrays and pointers) that are defined inside a block
    have undefined value when they are default initialized
  - if a class has a member that has a class type, and that class doesn’t have a default constructor, then
    the compiler can’t initialize that member

- Classes that use vectors and strings avoid the complexities involved in allocating and deallocating memory.

- The only difference between `struct` and class is the default access level: if we define members before the first access specifier:

  - with `sturct`: these members are `public`
  - with `class`: these members are `private`

- `friend` 只用于声明函数的访问级别，不用于声明函数。所以，若要使用函数，则还需要在class外再次声明对应的函数。（某些compiler没有硬性要求）

- `friend`标识的类或函数可以访问当前类的non-public members

- member functions defined inside the class are automatically `inline`

- When we provide an in-class initializer, we must do so following an = sign or inside braces.

  - `int a = 0;` / `vector\<int\> ints {0};`

- a class can not have data member of its own type, because 成员属性的type必须是complete define的，but a class is not defined until its class body is complete. But，a class can have data members that are pointers or references to its own type

- friendship is not transitive

- class members initializer versus class members assignment

  - ```c++
    // assignment
    Sales_data::Sales_data(const string s&, unsigned cnt, double price)
    {
        bookNo = s;
        units_sold = cnt;
        revenue = cnt * price;
    }
    
    // initializer list
    Sales_data(const string s&, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) { }
    ```

  - We must use the constructor initializer list to provide values for members that are `const`, reference, or of a class type that does not have a default constructor

- delegating constructors: Constructor with a constructor-initializer list that has one entry that designates another constructor of the same class to do the initialization.

  - ```c++
    class Sales_data {
        public:
        	Sales_data(std::string s&, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) {}
        	// delegate to another constructor
        	Sales_data(): Sales_data("", 0, 0) {}
        	Sales_data(std::string s): Sales_data(s, 0, 0) {}
        	Sales_data(std::istream &is): Sales_data() {
                read(is, *this);
            }
    }
    ```

- converting constructors: A constructor that can be called with a single argument defines an implicit conversion from the constructor’s parameter type to the class type.

  - ```c++
    string null_book = "9-9999-9999-9";
    
    item.combine(null_book);
    ```

  - 只含有一个实参的constructor会定义一个隐式的转换：将参数类型直接转化为对应的class类，例子中就将`null_book`转换为了`Sales_data`类

  - 可以通过在constructor前添加`explicit`关键字，防止compiler进行隐式转换，关键字只能用于修饰，在class内部，仅带有一个实参的constructor

## static class members

静态成员与class联系，与object无关，object内不存储static成员，所有object共享static成员。这就使得static成员函数不能通过`this`来获取当前的object对象，所以static成员函数不可以用`const`标识，也不能在函数体内部使用`this`。

```c++
class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};
```

可以类加范围操作符`Class::static_func()`、对象、指针、引用来访问static成员，非静态成员函数内部可以直接访问static成员函数（line 3）。

通常而言，我们在class内部声明static成员，在外部定义、初始话static成员（`const integral type`以及`constexpr literal type`除外）。

> `constexpr`标识的变量本身是隐式的`const`，且必须被常量表达式初始化；`constexpr`变量的值无法改变且必须在编译期就确定它的值

function内部的static变量需要在使用前被初始化，且变量的生命周期不会随函数的结束而结束，而是维持到程序结束。

> Even if a const static data member is initialized in the class body, that member ordinarily should be defined outside the class definition.

```c++
#include <iostream>
using namespace std;

class X {
    public:
    const static int a = 1; // declaration
};

// const int X::a; // definition

void test(const int& a) {
    cout << a << endl;
}

int main() {
    X x;
    test(x::a); // error: undefined reference to 'X::a'
    return 0;
}

// https://stackoverflow.com/questions/23439848/whether-redeclare-a-const-static-variable-outside-a-class-or-not
```

static成员与non-static成员还有两点用法上的区别：

- static成员可以是不完全的类型

  - ```c++
    class Bar {
        private:
        	static Bar mem1; // ok: static member can have incomplete type
        	Bar *mem2; // ok: pointer member can have incomplete type
        	Bar mem3; // error: data member can not have incomplete type
    }
    ```

- static成员可以作为函数的默认参数

  - ```c++
    class Screen {
    public:
    	// bkground refers to the static member
    	// declared later in the class definition
    	Screen& clear(char = bkground);
    private:
    	static const char bkground;
    };
    ```