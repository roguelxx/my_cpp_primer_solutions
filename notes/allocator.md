## allocator

`new`关键字创建的新对象可以分为两步，首先为这个对象申请内存空间（allocation），然后在内存上初始化（initialization）对象。`delete`关键字销毁对象也可以分为两步，首先调用对象的`destructor`，然后释放内存空间（deallocate）。这两个关键字将内存空间和初始化紧密的结合在一起，如果我们希望先分配一块内存空间，而对于内存空间中的对象可以“按需初始化”，那么就需要借由`allocator`实现。

```c++
string *const p = new string[n]; // construct n empty strings
string s;
string *q = p; // q points to the first string
while (cin >> s && q != p + n)
	*q++ = s; // assign a new value to *q
const size_t size = q - p; // remember how many strings we
read
// use the array
delete[] p; // p points to an array; must remember to use delete[]
```

如上所示，p的创建需要初始化n个空string，但是我可能不需要使用到n个对象；如果后面需要给array中的对象赋值，则需要对array中的对象进行两次写操作，一次在初始化时，一次在赋值时，这显然是浪费时间的。同时，array的初始化要求array中的对象需要有默认构造器（default constructor）。

### The allocator class

常见的与之相关的函数：

![image-20210901153754268](/home/lxx/Documents/books/c++/images/allocator-algorithm.png)

allocator和vector一样，是一个模板，所以定义allocator时需要指定模板类型（type）。通过`allocator.allocate(n)`申请n个type大小的内存空间，注意，内存空间中的type是没有初始化的（unconstructed）。我们需要通过`construct(p, args)`对内存空间中的type进行初始化，`args`必须与这个type的某个constructor参数相匹配。一般的使用流程如下：

```c++
allocator<string> a;
// allocate unconstructed objects
auto const p = a.allocate(n); // p points to one past the last constructed element
auto q = p;
// construct objects
a.construct(q++); // construct empty string
a.construct(q++, 10, 'c'); // construct "cccccccccc"
a.construct(q++, "hi"); // construct "hi"
// destroy objects
while(q!=p)
    a.destroy(--q);
// deallocate objects
a.deallocate(p, n);
```

### Algorithms to Copy and Fill uninitialized memory

![image-20210901160311954](/home/lxx/Documents/books/c++/images/allocator-algorithms-2.png)

假设我们有一块动态内存空间和`vector<int> vi`，空间大小是vector的两倍；首先将vector复制到前半部分的空间中，然后通过fill填充后半部分的空间：

```c++
allocator<int> a;
auto const p = a.allocate(vi.size()*2);
auto q = uninitialized_copy(vi.begin(),vi.end(),p); // q points to the one past last constructed element
uninitialized_fill_n(q, vi.size(), 42);
```

