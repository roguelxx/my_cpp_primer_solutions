- in C++, when we use an object as an `rvalue`, we use the object’s value (its contents). When we use an object as an `lvalue`, we use the object’s identity (its location in memory).

- `lvalue`: An expression that yields an object or function. A `nonconst` `lvalue` that denotes an object may be the left-hand operand of assignment.

- `rvalue`: Expression that yields a value but not the associated location, if any, of that value.

- By implication, if m%n is nonzero, it has the same sign as m.

- ```c++
  int k = 3.14; // k is 3
  int k = {3.14}; // error: narrowing conversion is not allowed when using initializer list
  ```

- The postfix operator must store the original value so that it can return the unincremented value as its result. So use postfix operators only when necessary

- small integral types: `bool, char, signed char, unsigned char, short, unsigned short`

- we can convert a pointer to a `nonconst` type to a pointer to the corresponding `const` type, and similarly for references. 反之不成立。

- named cast formulation: `cast-name<type>(expression);`

- `stactic_cast` usage: 将`void*` 指针转化为其他类型的指针

  - ```c++
    void* p = &d; // address of any nonconst object can be store in a void*
    double *dp = static_cast<double*>(p);
    ```

- `const_cast` 只能改变expression的`constness`，不能改变它的type

  - ```c++
    const char *cp;
    char *q = static_cast<char*>(cp); // error: static_cast can't cast away const
    static_cast<string>(cp); // ok: converts string literal to string
    const_cast<string>(cp); // error: const_cast only changes constness
    ```

- `reinterpret_cast` ? how to use it?