- C++ is a statically typed language; type checking is done at compile time

- a  `char` is the same size as a single machine byte

- The smallest chunk of addressable memory is referred to as a “byte.” The basic unit of storage, usually a small number of bytes, is referred to as a “word.”

- To give meaning to memory at a given address, we must know the type of the value stored there. The type determines how many bits are used and how to interpret those bits.

- The compiler appends a null character (’\0’) to every string literal.
  
  - the literal 'A' represents the single character A, whereas the string literal "A" represents an array of two characters, the letter A and the null character.
  
- an object is a region of memory that has a type.

- variables of built-in type defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is undefined

- declaration versus definition
  - declaration: Asserts the existence of a variable, function, or type defined elsewhere
  - definition: Allocates storage for a variable of a specified type and optionally initializes the variable
  - declaration + explicit initializer  = definition
  
- To obtain a declaration that is not also a definition, we add the `extern` keyword and may not provide an explicit initializer

- reference: an alias for another object
  - refers to ... (is another name for ...)
  - a reference may be bound only to an object, not to a literal or to the result of a more general expression
  - a reference is not an object
  
- `void*` is a special pointer type that can hold the address of any object

- `int *&r = p;` -> r is a reference to the pointer p
  
  - The easiest way to understand the type of r is to read the definition right to left. The symbol closest to the name of the variable (in this case the & in &r) is the one that has the most immediate effect on the variable’s type. Thus, we know that r is a reference. The rest of the declarator determines the type to which r refers. The next symbol, * in this case, says that the type r refers to is a pointer type. Finally, the base type of the declaration says that r is a reference to a pointer to an int.
  
- to share a `const` object among multiple files, we must define the variable as `extern`

- a reference to `const` may refer to an object that is Not `const`

  - ```c++
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    r1 = 0;				// r1 is not const; i is now 0
    r2 = 0;				// error: r2 is a reference to const
    ```

- We may store the address of a `const` object only in a pointer to `const`

  - we can use a pointer to `const` to point to a `nonconst` object:

- It may be helpful to think of pointers and references to `const` as pointers or references “that think they point or refer to `const`.”

  - 但是指向的对象是否是`const`，我们不得而知

- top-level `const` indicates that an object itself is `const`，即指针本身是`const`

- Low-level `const` appears in the base type of compound types such as pointers or references，指针指向的对象是`const`

- ![image-20210625124814832](/home/lxx/Documents/books/c++/images/top&low-level-const.png)

- Variables declared as `constexpr` are implicitly `const` and must be initialized by constant expressions

  - A constant expression is an expression whose value cannot change and that can be evaluated at compile time

- `decltype` returns the type of its operand

  - `decltype(f()) sum = x; // sum has whatever type f returns`

- 不是太懂`decltype` & `const` & `auto`

- preprocessor: Program that runs as part of compilation of a C++ program.

- 在class外define函数时，return type appears before the name of the class is seen, 所以我们要专门指明我们想要返回的是哪个class的成员属性。

  - ```c++
    Window_mgr::ScreenIndex
    Window_mgr::addScreen(const Screen &s)
    {
        screens.push_back(s);
        return screens.size() - 1;
    }
    ```

- Function bodies are compiled after compiler processes all of the declarations in the class, 所以我们可以在函数体内使用任意一个在class内声明的成员属性

- class内重新typedef的type不能覆盖outer type

- rvalue: Expression that yields a value but not the associated location, if any, of that value.

- lvalue: An expression that yields an object or function. A nonconst lvalue that denotes an object may be the left-hand operand of assignment

  - when we use an object as an rvalue, we use the object’s value (its contents). When we use an object as an lvalue, we use the object’s identity (its location in memory)