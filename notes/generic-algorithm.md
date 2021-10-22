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

# Exercises

10.5，10.7， 10.8