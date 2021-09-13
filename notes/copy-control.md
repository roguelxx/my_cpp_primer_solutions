自定义class时，c++允许我们控制这个class的object在赋值（assignment），复制（copy），销毁（destroy）时的动作。这些控制函数被称为copy contorl member function，具体分为copy constructor，copy assignment operator，destructor。

copy constructor控制了当object通过复制另一个同类型object进行初始化时的动作。copy assignment operator控制了通过赋值运算符（=）给object赋值时的动作。destructor控制了object被销毁时的动作。

如果我们在写class时没有显示的写出这些copy control member function，编译器会为我们生成默认的对应的member function。所以，一般情况下，我们确实可以忽略不写，但是当class中涉及到指针时，通常我们希望自己控制copy contorl。

## Copy Constructor

copy constructor的写法与default constructor类似，不同的是构造器中的参数是这个class type的引用：

```c++
class Foo {
    Foo(); // default constructor
    Foo(const Foo &); // copy constructor
}
```

拷贝构造器一般不申明为explicit，同时，参数必须是class type的引用。因为在函数传参的时候，非引用类型的参数的创建是通过拷贝构造器完成的，如果拷贝构造器的参数依然是非引用类型的参数，那么拷贝构造器的参数构造又要调用拷贝构造器，从而形成一种死循环。因此，参数必须是class type的引用类型。

如果我们没有显示的声明copy constructor，编译器会为我们生成合成拷贝构造器（synthesized copy constructor）。合成拷贝构造器将另一个object中的非静态（nonstatic）成员变量逐个拷贝到当前object。非静态成员变量的类型决定了这个成员变量是如何被拷贝的：如果是class type的成员变量，则调用这个class的拷贝构造器；如果是内置type或复杂type（指针），则直接拷贝；如果是array type，则一次调用element对应的拷贝构造器。

### direct initializationi vs. copy initialization

直接初始化是让编译器通过参数匹配找到合适的函数为我们创造一个对象，拷贝初始化是让编译器用右边的对象初始化左边的对象。

```c++
string dots(10, '.'); // direct initialization
string s(dots); // direct initialization
string s2 = dots; // copy initialization
string null_book = "9-999-99999-9"; // copy initialization
string nines = string(100, '9'); // copy initialization
```

拷贝初始化就会调用这个class的拷贝构造器，如果class定义了move构造器，有时会调用class的move构造器。

拷贝初始化不仅仅发生在等于号（=）的拷贝操作时，一下情况也属于拷贝初始化：

- 对象作为参数传入非引用类型的参数
- 对象作为返回值从函数返回，返回值类型必须是非引用类型
- 通过brace initialization初始化数组时

容器库提供的容器在初始化时都使用了拷贝初始化对容器内的元素进行拷贝，在insert或push的时候也会调用拷贝初始化；相反的，emplace调用的是直接初始化。

### initialization vs. assignment

这两个操作可能都包含等于号（=），不同的是，初始化（构造）对象是让编译器为我们创建一个新的对象；赋值操作是让编译器用操作符右边的对象初始化左边的对象，没有创建新的对象：

```c++
Foo f1 = f2; // copy initialization
Foo f3;
f3 = f1; //copy assignment
```

### Copy-Assignment Operator

拷贝赋值操作符控制了对象在被赋值的时候的行为，写法如下：

```c++
Foo & operator=(const Foo &) {
    // bla bla bla
    return *this;
};
```

返回值是class的引用，函数名为operator加上操作符（=），参数通常是class的常量引用。拷贝赋值操作符必须作为class的成员函数申明。

编译器生成的合成拷贝赋值操作符，将等于号右边的对象的非静态值拷贝到左边的对象中。

### Destructor

析构函数释放对象占有的资源，销毁对象的非静态成员变量。

构造函数（constructor）分为初始化部分和函数体部分，在函数体执行前，函数成员已经被初始化了，初始化的顺序与成员在class内的顺序一致；析构函数（destructor）分为函数体、析构部分，先执行函数体部分，然后才开始逐一销毁对象，销毁的顺序与class内申明的顺序相反。

销毁对象的行为与对象类型有关，class类型的对象的销毁会调用对应的destructor，内置类型、复杂类型（指针）没有destructor，所以它们的销毁（默认）不会做任何事。所以通常我们必须手动的释放指针指向的内存（智能指针除外）。

析构函数本身不会直接销毁对象的成员变量，只有当析构函数运行结束后，才会逐个销毁成员变量，比如调用string变量对应的destructor。

