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

#### q1025



#### q1084

```c++
#include<algorithm>

transform(s.begin(),s.end(),s.begin(),::toupper);
//将string类字符串转换为大写 ::tolower

#include<string>
getline(cin,str);//获取带有空格的字符串
```







## 算法初步

### 排序 P87

1. 冒泡排序
2. 选择排序：分有序区和无序区，每趟从无序区中选出最小的放到有序区后面。算法复杂度O(n^2)。
3. 插入排序：将无序区第一个元素在有序区中找到一个合适的位置插入

C++中sort函数实现排序功能。

```C++
#include<algorithm>
sort(首元素地址，尾元素地址的下一个地址，[比较函数]);
//不写比较函数，默认递增

bool cmp(int a,int b){
    return a>b;//从大到小排序
}

bool cmp(node a, node b){
    return a.x>b.x;//node为结构体
}

bool cmp(node a, node b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y<b.y;//先按x从大到小，再按y从小到大
}

```

对于容器，sort函数只能用于vector、string、deque的排序。

```C++
sort(vi.begin(),vi.end(),cmp);
```

对应题目：

![image-20201126182054450](https://i.loli.net/2020/11/26/m64BPciLpkUtTIC.png)



### 散列（hash）P128

hash:将一个元素通过一个函数转化为整数，使该整数可以尽量唯一地代表该元素。

```c++
//key为整数
除留余数法：H(key) = key % mod，mod最好为素数。

避免冲突：
1. 线性探查法
2. 平方探查法
3. 链地址法：将所有hash值相同地key连接成一条链表
前两种方法都要寻找新的hash值。
```

```
//key为字符串
将A-Z视为0-25，每个字符串可以转换为1个整数作为它地hash值。
```

```C++
//map用法
#include<map>
map<typename1,typename2> mp;
map<char,int> mp;
//通过下标访问
mp['c']=20;
mp['c']=30;
//通过迭代器访问
map<typename1,typename2>::iterator it;
it->first;//访问key
it->second;//访问值
//map自动按照key从小到大的顺序排序。

常用函数：
1、find(key);//返回对应迭代器
2、mp.erase(it or key);//删除单个元素
   mp.erase(first,last);//last为末尾迭代器的下一个地址
3、size()
4、clear()
```



对应题目：

![image-20201126184636406](https://i.loli.net/2020/11/26/DxeFJd4pgXUIkwV.png)



### 递归



### 贪心 P148



求解最优化问题的一种方法，总是考虑在当前状态下局部最优（较优）策略，来使全局的结果达到最优（较优）。











对应题目：

![image-20201126184716940](https://i.loli.net/2020/11/26/3yNE2HPASkrndDW.png)