# pat

#### q1005

大整数运算（该题为10^100），可以先用字符数组输入然后再做处理，每一位减去‘0’得到该位对应数值。

```C++
strlen(字符数组名)//求字符串长度
string 字符串对象
```



#### q1011

```C++
#include<iomamip>//控制输入输入格式
cout<<setprecision(4);//输入四位有效数字
```



#### q1015

```C++
#include<vector>
vector<int> a;//定义向量，相当于边长数组
a.push_back(temp);//添加一个值
```

本题先将一个素数转为D进制，然后反转，在转为10进制判断是否位素数。若是，则是reversible primes。

如：23 二进制10111 反转为11101，十进制是29，为素数，所以23是reversible primes。



#### q1009

```C++
#include<iomanip>
cout<<setiosflags(ios::fixed)<<setprecision(1);
//保留一位小数
如果是加法，次数是0-1000，可以用数组来保存对应系数。
本题是两个多项式相乘，次数最多可以是1000000，无法用数组来保存对应系数，可以采用链表来表示一个多项式。
系数相乘相加后若为0，则应该删去。
```

