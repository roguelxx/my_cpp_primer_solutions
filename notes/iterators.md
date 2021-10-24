## Insert Iterators

inserter可以理解成是迭代器的适配器，向inserter赋值时，inserter会调用对应的container的操作，向特定的位置插入一个元素。有三种类型的inserter：

- `back_inserter` -> `push_back(v)`

- `front_inserter` -> `push_front(v)`

- `inserter` -> `insert(v, p)`：在p前面插入v，且保持p不变

  - ```c++
    // it 是inserter产生的迭代器
    *it = val;
    // equals to
    it = c.insert(it, val);
    ++it; // increment it so that it denotes the same element as before
    ```

只有当container支持相应的操作时，inserter才有用，比如：只有支持`push_back()`的container才可以使用`back_inserter`插入元素。

```c++
list<int> lst = {1, 2, 3, 4};
list<int> lst2, lst3;
copy(lst.begin(), lst.end(), front_inserter(lst2)); // {4, 3, 2, 1}
copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin())); // {1, 2, 3, 4}
```

## iostream iterator

