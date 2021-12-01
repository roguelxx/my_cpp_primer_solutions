- automatic objects: Objects that exist only during the execution of a function. They are created when control passes through their definition and are destroyed at the end of the block in which they are defined.

- uninitialized local variables of build-in type have undefined values

- local `static` objects 在function返回后仍然存在，同时它只会被初始化一次。

  - ```c++
    size_t count_calls()
    {
        static size_t ctr = 0; // value will persist across calls
        return ++ctr;
    }
    
    int main()
    {
        for (size_t i=0;i!=10;++i)
            cout<<count_calls()<<endl;
        return 0;
    }
    ```

- If the parameter is a reference , then the parameter is bound to its argument. Otherwise, the argument’s value is copied.

- pointers parameter behave like any other non-reference type. When we copy a pointer, the value of the pointer is copied, the two pointers are distinct. 但是此时可以通过新的指针改变指向的对象的值。

- Reference parameters that are not changed inside a function should be references to `const`.

- using references as parameter can avoid copies

- why we must not change the size of a container within range for?

  - In a range for, the value of end() is cached. If we add elements to (or remove them from) the sequence, the value of end might be invalidated

- top-level `const` on parameters are ignored. We can pass either a `const` or a `nonconst` object to a parameter that has a top-level `const`

  - ![image-20210704163823108](/home/lxx/Documents/books/c++/images/const-parameter.png)

- Pointer or Reference Parameters and `const` 没看懂

  - 可以用`non-const object`初始化low-level `const`， 反之不行
  - 普通引用必须用相同类型的对象初始化

- 如果function内不会修改vector、string，那么实参应该用`const`标识，着同样适用于array参数

- 当实参是array的引用时，实参array的维度是实参的一部分，形参必须是相同长度的array。同时还要注意数组的引用的写法；

  - ```c++
    void print(int (&arr)[10])
    {
        for (auto item : arr)
            cout << elem <<endl;
    }
    
    int i=0, j[2]={0,1};
    int k[10] = {0,1,2,...,9};
    print(&i); //error
    print(j); //error
    print(k);
    ```

- `initializer_list`: template type same as `vector`, represents an array of `const` elements

  - must passed a sequence of values to `initializer_list` in curly braces

  - ```c++
    void error_msg(initilizer_list<string> il)
    {
        for (auto beg = il.begin(); beg != il.end(); ++beg)
            cout << *beg << " ";
        cout << endl;
    }
    
    error_msg({"functionX", expected, actual}); // expected, actual are strings
    ```

- Calls to functions that return references are `lvalues`; other return types yield `rvalues`.

- form of a function that returns a pointer to an array : `Type (*function(parameter_list))[dimension]`

  - `int (*func(int i))[10];` 返回指向包含10个int的array的指针的函数

- using trailing return type

  - `auto func(int i) -> int (*)[10];`

- Overloading and `const` Parameters P305

- if we declare a name in an inner scope, that name hides uses of that name declared in an outer scope

  - ```c++
    string read();
    void print(const string&);
    void print(double);
    void fooBar(int ival)
    {
        bool read = false; // hide the outer declaration of read
        string s = read(); // error
        void print(int); // new scope: hide previous instances of print
        print("Value: "); // error
        print(ival); //ok
        print(3,14); // ok: calls print(int); print(double) is hidden
    }
    ```

- The value that those names represent is evaluated at the time of the call

  - ```c++
    typedef string::size_type sz;
    sz wd = 80;
    char def = '';
    sz ht();
    string screan(sz = hit(), sz = wd, char = def);
    string window = screen(); // calls screan(ht(), 80, '')
    
    void f2()
    {
        def = '*'; // changes the value of a default argument
        sz wd = 100; // hides the outer definition of wd but does not change the default
        window = screen(); // calls screen(ht(), 80, '*')
    }
    ```

- `inline` function: Request to the compiler to expand a function at the point of call, if possible. `Inline` functions avoid the normal function-calling overhead.

- `constexpr` function restrictions:

  - `return` type and the type of each parameter must be a literal type
  - function body must contain exactly one `return` statement
  - while, `constexpr` function is not required to return a constant expression

- preprocessor names are managed by the preprocessor not the compiler.

- steps of function matching
  - identify the set of overload functions (candidate functions)
    - 在被调用时，可见的，与被调用函数拥有相同函数名的函数
  - select from candidate functions those functions (viable functions)  that can be called with the arguments in the given call.
    - When a function has default arguments, a call may appear to have fewer arguments than it actually does.

- form of pointers to function, `return type (*pointer_name)(parameters)`