根据向container添加、删除元素的效率和随机访问container的效率，可以将container分为以下几类：

![image-20211025145134705](/home/lxx/CLionProjects/my_cpp_primer_solutions/notes/images/sequential-container-types.png)

容器对元素的存储方式决定了容器操作的效率，以vector和string为例，二者存储的元素在内存中是一块连续的空间，所以随机访问效率高，但是增删元素效率低；最差情况下，当增加一个元素后，需要重新申请一块更大的空间，将原来的数据复制到新的内存空间。

`forward_list`和`array`是在新标准中添加的容器，`array`是固定大小的，不支持增删操作；`forward_list`是单向链表，增删快，随机访问慢，且不支持`size()`操作，因为计算大小需要从头遍历链表。

## Which sequential container to use

- 一般情况下，`vector`即可满足
- 使用`list`、`forward_list`会增加存储开销
- 如果需要在容器中间增删元素，则使用`list`、`forward_list`
- 如果需要在头尾增删元素，则使用`deque`
- 如果需要支持多种操作，

如果暂时不能决定用什么容器，可以使用通用的迭代器写法，



- size_t : Machine-dependent unsigned integral type defined in the `cstddef` header that is large enough to hold the size of the largest possible array.
- size_type : Name of types defined by the string and vector classes that are capable of containing the size of any string or vector, respectively. Library classes that define size_type define it as an unsigned type.