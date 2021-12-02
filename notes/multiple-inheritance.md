- 类继承列表中的access specifier如果忽略了，compiler会给予默认访问标识符。如果继承自其他类，默认private；如果继承自其他struct，默认public
- 子类构造器中只初始化它的直接继承类（direct base class）
- 类成员的可见度由对象的静态类型决定（static type），父类对象只能看到父类中定义的成员，子类同理
- 多继承情况下，函数的look up同时进行，如果编译器发现多个相同名称的函数，则会报错
  - name look up发生在类型检测前，同名不同参数列表的函数在多继承情况下也会被认为是同名函数，也会报错



虽然类继承列表中不能多次继承同一个类，但是仍然有可能间接的多次继承同一个类：

![image-20211201164116322](images\virtual-inheritance.png)

以上图为例，如果按照正常的继承的规则，子类中会包含父类的部分（part），那么Panda内就会由两个ZooAnimal subobjet，一个继承自Bear，一个继承自Raccoon；我们希望Panda内只存在一份ZooAnimal subject，所以虚拟继承（virtual inheritance）就是来解决这种情况的。

类通过虚拟继承来表示它愿意将这个继承的基类与其他类共享（share its base class），这个基类称为virtual base class。上图中的ZooAnimal。

### Constructs and virtual inheritance

虚拟继承中的name look up与普通继承一样，但是构造器的调用过程是不一样的。

如果按照普通继承中的构造器调用规则，那么virtual base class就会被多次construct，上图为例，一次通过Bear调用，一次通过Raccoon调用，这显然是不正确的。在虚拟继承中，只要我们需要创建继承自virtual base class的子类的对象，这个子类就需要构造virtual base class。

```c++
Bear::Bear(std::string name, bool onExhibit): ZooAnimal(name, onExhibit, "Bear") { }
Raccoon::Raccoon(std::string name, bool onExhibit): ZooAnimal(name, onExhibit, "Raccoon") { }
```

创建Panda对象时，即使ZooAnimal不是它的直接父类，也需要调用ZooAnimal的构造器：

```c++
Panda::Panda(std::string name, bool onExhibit): ZooAnimal(name, onExhibit, "Panda"), Bear(name, onExhibit),
												Raccoon(name, onExhibit), Endangered(Endangered::critical),
												sleeping flag(false) { }
```

同时，构造的顺序发生了变化：先调用virtual base class的构造器，在按继承列表中的顺序调用直接父类的构造器。即虚拟基类的初始化先于非虚拟基类的初始化。

如果没有显示的调用virtual base class的构造器，则会调用virtual base class的默认构造器，如果virtual base class没有默认构造器，那么就会编译报错。