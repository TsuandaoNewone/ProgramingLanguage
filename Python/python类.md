##### 命名空间：

三种名称空间：

1. Global	

   模块中的函数、类、模块级的变量与常量，其他导入的模块

2. Local

   函数拥有的命名空间

3. Built-in

   内置命名空间，放着内置的函数和异常

名称空间的加载顺序

内置命名空间(程序运行前加载)-->全局命名空间(程序运行中：从上到下加载)-->局部命名空间(程序运行中：调用时才加载)

~~~python
#-- 命名空间就是name：object的映射，
#-- nonlocal关键字访问上一级的命名空间，只能访问不能定义闭包
#-- global关键字访问全局的名称空间，可以访问也可以定义新的全局变量

def scope_test():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam
        spam = "global spam"

    spam = "test spam"
    do_local()
    print("After local assignment:", spam)
    do_nonlocal()
    print("After nonlocal assignment:", spam)
    do_global()
    print("After global assignment:", spam)

scope_test()
print("In global scope:", spam)

After local assignment: test spam
After nonlocal assignment: nonlocal spam
After global assignment: nonlocal spam
In global scope: global spam
~~~

##### 类

1. 类的定义
2. 类的初始化：_\_init\__
3. self与函数调用的真正含义
4. 类的公共成员

~~~python
class Dog:

    kind = 'canine'         # class variable shared by all instances

    def __init__(self, name):
        self.name = name    # instance variable unique to each instance

>>> d = Dog('Fido')
>>> e = Dog('Buddy')
>>> d.kind                  # shared by all dogs
'canine'
>>> e.kind                  # shared by all dogs
'canine'
>>> d.name                  # unique to d
'Fido'
>>> e.name                  # unique to e
'Buddy'

#-- 在类中定义的成员都是共有成员
class Dog:

    tricks = []             # mistaken use of a class variable

    def __init__(self, name):
        self.name = name

    def add_trick(self, trick):
        self.tricks.append(trick)

>>> d = Dog('Fido')
>>> e = Dog('Buddy')
>>> d.add_trick('roll over')
>>> e.add_trick('play dead')
>>> d.tricks                # unexpectedly shared by all dogs
['roll over', 'play dead']

#-- 要想每个对象中的成员不同，则必须在_init_函数中定义
class Dog:

    def __init__(self, name):
        self.name = name
        self.tricks = []    # creates a new empty list for each dog

    def add_trick(self, trick):
        self.tricks.append(trick)

>>> d = Dog('Fido')
>>> e = Dog('Buddy')
>>> d.add_trick('roll over')
>>> e.add_trick('play dead')
>>> d.tricks
['roll over']
>>> e.tricks
['play dead']
~~~

##### 类的继承

~~~python
#--继承
class DerivedClassName(BaseClassName):
    <statement-1>
    .
    .
    .
    <statement-N>

#-- 多重继承
class DerivedClassName(Base1, Base2, Base3):
    <statement-1>
    .
    .
    .
    <statement-N>
~~~

