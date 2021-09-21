# Moving Objects

一些Class内的资源是不允许共享的，这个Class的对象之间只能通过move来转移所有权，不能通过拷贝（copy）。比如与IO相关的类以及`unique_ptr`，都是不支持copy，只能通过move转移资源的所有权。

## Rvalue References

为了支持move操作，C++11引入了新的引用类型，右值引用（rvalue references），顾名思义，只能绑定在右值（rvalue）的引用。

### lvalue and rvalue

左值可以放在赋值等号的左边，右值不可以。当一个object作为右值时，我们使用的是object的值（contents）；当一个object作为左值时，我们使用的是object本身（its location in memory）。一些操作符只能用在lvalue上：

- 赋值操作符的左边只能是lvalue（nonconst），赋值后的结果也是lvalue
- 取址符号（&）需要lvalue，产生的结果是rvalue
- 解析地址符号（*）以及下标访问符号（[]）需要lvalue，产生的结果是lvalue

rvalue是临时的，lvalue是持久的。

右值引用只能用来绑定右值：

```c++
int i = 42;
int &r = i; // ok: r refers to i
int &&rr = i; // error: cannot bind an rvalue reference to an lvalue
int &r2 = i * 42; // error: i * 42 is an rvalue
const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplication
```

可以看到，右值绑定的对象基本都是字面量、或临时对象，即马上要被destroy了；这就意味着使用右值引用的代码可以将这个对象的所有权move给其他对象。

特别注意的是变量本身是lvalue，所以我们不能用右值引用绑定（绑定了右值的）右值引用变量。

```c++
int &&rr1 = 42; // ok: literals are rvalues
int &&rr2 = rr1; // error: variables are lvalue
```

## The Library move Function

头文件`<utility>`提供了`std::move()`方法，用于将一个lvalue转化为对应的rvalue引用类型：

```c++
int &&rr3 = std::move(rr1)
```

> We can destroy a moved-from object and can assign a new value to it, but we cannot use the value of a moved-from object.

### move constructor

与copy constructor类似，move constructor将不可共享资源从moved-from object中“偷”来，给moved-to object；move constructor必须保证moved-from object的状态是处于可以被安全destroy的。

```c++
StrVec::StrVec(StrVec &&s) noexcept // move won't throw any exceptions
// member initializers take over the resources in s
: elements(s.elements), first_free(s.first_free), cap(s.cap) {
// leave s in a state in which it is safe to run the destructor
	s.elements = s.first_free = s.cap = nullptr;
}
```

可以看到move构造器中没有为moved-to对象分配新的内存空间，而是将moved-from对象的资源转移给了to对象，但是我们必须保证from对象的状态是允许被安全destroy的，如果我们没有将`s.first_free`指针置为空指针，那么from对象被销毁时就会释放`s.first_free`指向的内存空间，就会影响to对象的`first_free`。

`StrVec`的move构造器中还添加了`noexcept`关键字，来告诉编译器这个move构造器不会引起任何异常。这样做有两个原因：

- 特殊情况下，move构造器可能会抛出异常，所以当不会抛出异常时，我们需要显示的标识出来
- 一些函数保证了异常发生时对象不会受异常影响，比如`push_back`

所以vector只有当move构造器标识为noexcept时才使用move构造器进行reallocation，否则使用copy构造器，来保证万一有异常发生，vector的原数据不会受到影响。

### move assignment

move赋值同move构造器一样，如果可以保证不抛出异常，需要显式的标识出来；同时也要考虑自我赋值的情况：

```c++
StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	// direct test for self-assignment
	if (this != &rhs) {
		free(); // free existing elements
		elements = rhs.elements; // take over resources from rhs
		first_free = rhs.first_free;
		cap = rhs.cap;
		// leave rhs in a destructible state
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
```

> After a move operation, the “moved-from” object must remain a valid, destructible object but users may make no assumptions about its value.

### the synthesized move operations

如果class自己定义了任何一个copy构造器、copy赋值、destructor，那么compiler就不会为其生成move controller。只有当class没有定义任何copy controller且class的所有非静态（nonstatic）成员都可以被moved时（所有内置类型都可以被moved），compiler会为class生成move controller。

```c++
// the compiler will synthesize the move operations for X and hasX
struct X {
	int i; // built-in types can be moved
	std::string s; // string defines its own move operations
};
struct hasX {
	X mem; // X has synthesized move operations
};
X x, x2 = std::move(x); // uses the synthesized move constructor
hasX hx, hx2 = std::move(hx); // uses the synthesized move constructor
```

move controller在以下几种情况下会被标记为deleted：

- 某个成员没有move controller时，要么没有自定义，要么compiler无法为其生成
- 某个成员的move controller被标记为deleted或无法获取到（inaccessible）
- destructor被标记为delete或inaccessible（同copy controller）
- 当这个类有const或引用类型的成员时，move assignment被标记为deleted

```c++
// assume Y is a class that defines its own copy constructor but not a move constructor
struct hasY {
	hasY() = default;
	hasY(hasY&&) = default;
	Y mem; // hasY will have a deleted move constructor
};
hasY hy, hy2 = std::move(hy); // error: move constructor is deleted
```

反过来，如果class定义了自己的move controller，则必须显式的定义copy controller，否则copy controller将默认被标记为deleted。

copy operations的参数一般都为const左值引用类型，因为拷贝的过程中不允许修改copied-from对象；move operations的参数一般为nonconst右值引用类型，因为move过程中需要改变move-from对象的状态。

> Overloaded functions that distinguish between moving and copying a parameter typically have one version that takes a const T& and one that takes a T&&.

所以，当class既有copy operation又有move operation时，编译器通过普通的函数签名（参数、返回值）匹配来选择对应的operation。

```c++
StrVec v1, v2;
v1 = v2; // v2 is an lvalue; copy assignment
StrVec getVec(istream &); // getVec returns an rvalue
v2 = getVec(cin); // getVec(cin) is an rvalue; move assignment
```

一般而言，lvalue的赋值、构造会使用copy operation；rvalue的赋值、构造会使用move operation。

> If a class has a usable copy constructor and no move constructor, objects will be “moved” by the copy constructor. Similarly for the copy-assignment operator and move-assignment.

### rvalue references and member function

一些成员函数可以有move版本，通过参数的不同重写函数。以c++容器库中的vector为例，vector的push_back方法就有copy、move两种版本：

```c++
void push_back(const X&); // copy: binds to any kind of X
void push_back(X&&); // move: binds only to modifiable rvalues of type X
```

当传入的参数为rvalue时，就会调用move版本的push_back，减少copy的开销。

```c++
vec.push_back(s); // calls push_back(const string&)
vec.push_back("done"); // calls push_back(string&&)
```

### rvalue and lvalue reference member function

一般而言，我们在调用object函数时，不用考虑object是rvalue还是lvalue：

```c++
string s1 = "a value", s2 = "another";
auto n = (s1 + s2).find('a');
```

在新的标准下，c++允许我们规定class的某个成员函数只能被lvalue/rvalue调用，通过在参数列表后添加reference qualifier来标识：

```c++
class Foo {
public:
	Foo &operator=(const Foo&) &; // may assign only to modifiable lvalues
	// other members of Foo
};
Foo &Foo::operator=(const Foo &rhs) & {
	// do whatever is needed to assign rhs to this object
	return *this;
}
```

同const qualifier一样，reference qualifier只能用于修饰nonstatic成员函数，并且需要在class内外都申明。这里我们定义了Foo的copy assignment，规定了赋值等号左边必须为lvalue。

```c++
Foo &retFoo(); // returns a reference; a call to retFoo is an lvalue
Foo retVal(); // returns by value; a call to retVal is an rvalue
Foo i, j; // i and j are lvalues
i = j; // ok: i is an lvalue
retFoo() = j; // ok: retFoo() returns an lvalue
retVal() = j; // error: retVal() returns an rvalue
i = retVal(); // ok: we can pass an rvalue as the right-hand operand to assignment
```

通过reference qualifier的不同，我们也可以重写成员函数：

```c++
class Foo {
public:
	Foo sorted() &&; // may run on modifiable rvalues
	Foo sorted() const &; // may run on any kind of Foo
	// other members of Foo
private:
	vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}
// this object is either const or it is an lvalue; either way we can't sort in place
Foo Foo::sorted() const & {
	Foo ret(*this); // make a copy
	sort(ret.data.begin(), ret.data.end()); // sort the copy
	return ret; // return the copy
}
```

如果object是rvalue，那么它一定只有一个user，则我们可以放心的原地排序；如果object是lvalue，那么我们既要返回一份排序后的拷贝结果。

某个函数的重写版本之一使用了reference qualifier，则这个函数的其他所有版本都必须使用reference qualifier来区别彼此。

> If a member function has a reference qualifier, all the versions of that member with the same parameter list must have reference qualifiers.

```c++
class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const; // error: must have reference qualifier
	// Comp is type alias for the function type (see § 6.7 (p. 249))
	// that can be used to compare int values
	using Comp = bool(const int&, const int&);
	Foo sorted(Comp*); // ok: different parameter list
	Foo sorted(Comp*) const; // ok: neither version is reference qualified
};
```

