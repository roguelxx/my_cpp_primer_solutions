### Algorithm

- 大多数algorithm都要用到element的操作符，比如`find()`使用`==operator`来比较element，有要求element有实现`<operator`

- algorithm不会执行container的操作（add，remove），algorithm的操作都通过迭代器进行；这意味着algorithm不会改变container的大小

  - 特别地，如果algorithm要修改container，会通过特殊的iterator进行（Inserter）

- 对于不会修改container的algorithm，传入的迭代器参数使用cbegin()，cend()；如果需要对返回的结果迭代器进行修改，则需要传入begin()，end()

- 向目的iterator进行写操作的algorithm不会进行范围检查，常见错误：用`fill_n()`向空容器写东西

- 头文件`<iterator>`下的`back_inserter(container)`方法，返回一个iterator，这个iterator指向container的下一个新位置

  - ```c++
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 1); // appends 10 1 to vec, each assignment will call push_back() on vec
    ```

- 一些需要对container进行修改的algorithm会有“copy”版本，copy版本不会修改原container，而是输出到新的container

### Lambda

- lambda表达式是一段可以被调用的代码块（callable unit of code），具有以下形式

  - ![image-20211023133504584](/home/lxx/CLionProjects/my_cpp_primer_solutions/notes/images/lambda-expression-form.png)

  - capture list是包含lambda表达式的函数的局部变量（nonstatic）的列表，通常情况下为空

    - 函数体内可以使用static变量以及申明在surrounding函数外部的变量

    - ```c++
      for_each(vec.begin(), vec.end(), [](const string &s){cout << s << " ";};
      ```

    - 函数体内使用了头文件`<iostream>`中的cout函数

  - 可以省略参数列表和返回类型，但是必须包含capture list和函数体

  - 向一个函数传入lambda表达式时，编译器为我们定义了一个新的类型并创建了一个新类型的对象

- lambda的capture变量可以通过值传入，也可以通过引用传入；与函数参数列表不同的是，capture变量的值在创建lambda时就copy了，而不是在lambda被调用时才进行copy

  - ```c++
    void fun1() {
        size_t v1 = 42; // local variable
        // copies v1 into the callable object named f
        auto f = [v1]{return v1;};
        v1 = 0; // modify loval variable
        auto j = f(); // j is 42; f stored a copy of v1 when we created it
    }
    
    void fun2() {
        size_t v1 = 42;
        auto f = [v1]{ return v1; };
        v1 = 0;
        auto j = f(); // j is 0;
    }
    ```

  - ![image-20211023145620253](/home/lxx/CLionProjects/my_cpp_primer_solutions/notes/images/capture-rules.png)

- 通过vaue传入的capture变量，在函数体内是无法修改这个变量的；如果我们需要修改这种变量，需要加上`mutable`关键字，此时参数列表无法省略

  - ```c++
    void fun3() {
      std::size_t v1 = 42;
      auto f = [v1]() mutable { return ++v1; };
      v1 = 0;
      auto j = f();
      std::cout << j << ", " << v1; // 43, 0
    }
    ```

### Bind

定义在`<functional>`头文件中，可以理解成是函数的适配器（adaptor is a mechanism for making one thing act like another），通常的使用形式：`auto new_callable = bind(callable, arg_list)`。通过`bind()`将`callable`与`arg_list`绑定起来，调用`new_callable`将会以`arg_list`作为参数，调用`callable`。

`arg_list`中的参数如果以`_n`的形式写出来，则表示该参数对应`new_callable`的第n个参数。使用这种写法需要声明命名空间`using std::placeholders::_1`。

```c++
// 假设f是有五个参数的函数
auto g = bind(f, a, b, _2, c, _1); // g是需要两个参数的函数
// g(_1, _2) -> f(a, b, _2, c, _1)
g(X, Y) -> f(a, b, Y, c, X)
```

默认情况下，通过占位符`_n`传入的参数以值拷贝（copy）的形式传递，如果想要以引用的形式传递，需要调用`ref()`函数。

```c++
ostream & print(ostream &os, const string &s, char c) {
    return os << s << c;
}
// os is a local variable referring to an ouput stream
for_each(vec.begin(), vec.end(), bind(print, os, _1, ' ')); // error
for_each(vec.begin(), vec.end(), bind(print, ref(os), _1, ' '));
```

# Exercises

10.5，10.7， 10.8