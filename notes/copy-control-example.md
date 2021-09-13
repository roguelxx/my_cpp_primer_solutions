## Target

实现两个类，Message和Folder；Message可以出现在多个Folder中；Folder中可以存放多个不同的Message。Folder和Message的关系图如下：

<img src="/home/lxx/Documents/books/c++/images/msg-fder-rel.png" alt="image-20210824144418949" style="zoom:50%;" />

### Message

支持两种操作：Save和Remove。Save将一个Message添加至指定Folder，Remove从指定Folder中删除一个Message。创建Message时，我们只创建Message的内容，但不指定存放Message的Folder，所以，创建Message之后要通过Save来指定存放的Folder。

当我们复制一个Message时，复制体和本体是两个不同的Message，但是他们需要保存在相同的Folder下，即拷贝Message需要拷贝Message的内容以及本体中指向Folders的指针，同时也要在这些Folders中添加指向拷贝Message的指针。

当我们销毁一个Message时，需要删除所有指向这个Message的指针。

当我们进行Message的赋值操作时，我们需要将左值Message的内容替换为右值Message的内容，同时也要更新Folders，删除左值Message所在的Folder中的指针，向右值所在的Folder添加指向左值Message的指针。

可以看到，拷贝Message和赋值Message的操作中都需要向多个Folder添加Message指针这样的功能，所有可以将这个功能提取出来作为utility函数。

## Addition

### friend

class的私有成员变量不允许class外的使用者访问，如果我们希望某个函数或class可以访问另一个class的私有成员变量，可以通过friend关键字申明需要访问权的函数或class。

friend申明可以出现在class的任何地方，且不受当前访问控制符的印象（private，public）。

friend申明不同于普通的函数申明，它只是用来告诉编译器，friend函数或class的访问权。所以如果我们希望class的使用者可以使用这个class的friend函数或class，则需要在class外部再次申明这个函数或class。

