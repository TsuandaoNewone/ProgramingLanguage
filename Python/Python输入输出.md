**输出格式**

~~~Python
#--格式化字符串常量
#插入常量
>>> year = 2016
>>> event = 'Referendum'
>>> f'Results of the {year} {event}'
'Results of the 2016 Referendum'
#控制长度和小数点位数
>>> yes_votes = 42_572_654
>>> no_votes = 43_132_495
>>> percentage = yes_votes / (yes_votes + no_votes)
>>> '{:-9} YES votes  {:2.2%}'.format(yes_votes, percentage)
' 42572654 YES votes  49.67%'

>>> table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
>>> for name, phone in table.items():
...     print(f'{name:10} ==> {phone:10d}')
...
Sjoerd     ==>       4127
Jack       ==>       4098
Dcab       ==>       7678

#--格式化字符串中值的传递
>>> print('We are the {} who say "{}!"'.format('knights', 'Ni'))
We are the knights who say "Ni!"
>>> print('{0} and {1}'.format('spam', 'eggs'))
spam and eggs
>>> print('{1} and {0}'.format('spam', 'eggs'))
eggs and spam
>>> print('This {food} is {adjective}.'.format(
...       food='spam', adjective='absolutely horrible'))
This spam is absolutely horrible.
>>> print('The story of {0}, {1}, and {other}.'.format('Bill', 'Manfred',
                                                       other='Georg'))
The story of Bill, Manfred, and Georg.

#--
>>> '12'.zfill(5)
'00012'
>>> '-3.14'.zfill(7)
'-003.14'
>>> '3.14159265359'.zfill(5)
'3.14159265359'
~~~

~~~python
#--repr()
>>> s = 'Hello, world.'
>>> str(s)
'Hello, world.'
>>> repr(s)
"'Hello, world.'"
>>> hello = 'hello, world\n'
>>> hellos = repr(hello)
>>> print(hellos)
'hello, world\n'
>>> print(f'My hovercraft is full of {animals!r}.') #!r
My hovercraft is full of 'eels'.
~~~

**文件读写**

~~~python
>>> f = open('workfile', 'w')
#--r 只读，默认参数
#--w 只写，若有重名文件会被覆盖
#--a appedning，加入到文件末尾
#--r+ 读和写

#--with程序段结束后文件自动关闭
>>> with open('workfile') as f:
...     read_data = f.read()

>>> # We can check that the file has been automatically closed.
>>> f.closed
True
~~~

~~~python
#--f.read(size), 没有参数读取整个文件
>>> f.read()
'This is the entire file.\n'
>>> f.read()
''

>>> f.readline()
'This is the first line of the file.\n'
>>> f.readline()
'Second line of the file\n'
>>> f.readline()
''

>>> for line in f:
...     print(line, end='')
...
This is the first line of the file.
Second line of the file

>>> f.write('This is a test\n')
15
>>> f = open('workfile', 'rb+')
>>> f.write(b'0123456789abcdef')
16
>>> f.seek(5)      # Go to the 6th byte in the file
5
>>> f.read(1)
b'5'
>>> f.seek(-3, 2)  # Go to the 3rd byte before the end
13
>>> f.read(1)
b'd'
~~~

**标准数据表示格式：json**

~~~python
import json

json.dump(x, f)
x = json.load(f)
~~~

~~~
    def action(self, direction):
        if direction == 6:  # start
            self.start()
        elif direction == 5:  # 倒车入库
            if self.Direction == 2:
                self.spin_left()
            elif self.Direction == 3:
                self.spin_right()
                self.spin_right()
            elif self.Direction == 4:
                self.spin_right()
            if self.park == 1:
                self.left_back()
            else:
                self.right()
        elif direction == self.Direction:
            direction = self.Direction
            self.tracking()
        elif direction - self.Direction == 1 or direction - self.Direction == -3:  # spin right 90 degree
            self.spin_right()
            self.Direction = direction
            self.tracking()
        elif direction - self.Direction == -1 or direction - self.Direction == 3:  # spin left 90 degree
            self.spin_left()
            self.Direction = direction
            self.tracking()
        elif direction - self.Direction == 2 or direction - self.Direction == -2:  # spin right 180 degree
            self.spin_right()
            self.spin_right()
            self.Direction = direction
            self.tracking()

        if self.Direction == 1:
            self.posY = self.posY + 1
        elif self.Direction == 2:
            self.posX = self.posX + 1
        elif self.Direction == 3:
            self.posY = self.posY - 1
        elif self.Direction == 4:
            self.posX = self.posX - 1
~~~

