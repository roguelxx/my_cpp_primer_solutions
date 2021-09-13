- copy initialization: Form of initialization that uses an =. The newly created object is a copy of the given initializer. `string s1 = "cc";`

- direct initialization: Form of initialization that does not include an =. `string s1(2, 'c'); // s1 is cc`

- When we mix strings and string or character literals, at least one operand to each operator must be of string type
  
- ![image-20210627180931345](/home/lxx/Documents/books/c++/images/string-add-rule.png)
  
- If we want to change the value of the characters in a string, we must define the loop variable as a reference type

  - ```c++
    for(auto &c : str)
        // do something
    ```

- Templates are not themselves functions or classes. Instead, they can be thought of as **instructions to the compiler for generating classes or functions**. The process that the compiler uses to create classes or functions from templates is called **instantiation**.

- `vector` is a template, not a type

- The body of a `range for` must not change the size of the sequence over which it is iterating.

- The subscript operator on vector (and string) fetches an existing element; it does not add an element.

- If the container is empty, the iterators returned by begin and end are equal

- `->` combines the operations of dereference and dot operations: `a->b == (*a).b`

- When we use this form of initialization, it is important to remember that string literals end with a null character. That null character is copied into the array along with the characters in the literal

  - ![image-20210628171400301](/home/lxx/Documents/books/c++/images/char-array-attention.png)

- We cannot initialize an array as a copy of another array, nor is it legal to assign one array to another
  
- ![image-20210628171551577](/home/lxx/Documents/books/c++/images/array-attention-1.png)
  
- It can be easier to understand array declarations by starting with the array’s name and reading them from the inside out.
  
  - ![image-20210628172458201](/home/lxx/Documents/books/c++/images/array-decl-`.png)
  - We start by observing that the parentheses around `*Parray` mean that `Parray` is a pointer. Looking right, we see that `Parray` points to an array of size 10. Looking left, we see that the elements in that array are `ints`. Thus, `Parray` is a pointer to an array of ten `ints`.
  
- ```c++
  #include <iterator>
  
  int ia[] = {0,1,2,3,4,5};
  int *beg = begin(ia);
  int *last = end(ia);
  ```

- Character string literals are an instance of a more general construct that C++ inherits from C: **C-style character strings**. i.e. , end with '\0'

- `strlen()` \ `strcmp()` \ `strcat()` \ `strcpy()` should passed C-style character strings

- Remember that when we use an array, we are really using a pointer to the first element in the array

- ```c++
  char *str = s; // error: can not initialize a char* from a string
  const char *str = s.c_str(); // ok
  ```

- ```c++
  // using array to initialize a vector
  int ia[] = {0,1,2,3,4};
  vector<int> iv(begin(ia), end(ia));
  ```

- 